#include <stdio.h>

#define MAX 100010

typedef long long ll;

typedef struct {
    int pos, val;
} OP;

OP ops[MAX];

void copy(OP *a, OP *b){
    a->pos = b->pos;
    a->val = b->val;
}

void swap(OP *a, OP *b){
    OP tmp;
    copy(&tmp, a);

    a->pos = b->pos;
    a->val = b->val;

    b->pos = tmp.pos;
    b->val = tmp.val;
}

void insertSort(int l, int r){
    for(int i = l + 1; i < r; i++){
        if(ops[i].pos < ops[i-1].pos){
            int j = i - 1;
            while(j - 1 >= l && ops[i].pos < ops[j - 1].pos) j--;

            OP tmp;
            copy(&tmp, &ops[i]);

            for(int t = i; t > j; t--){
                copy(&ops[t], &ops[t - 1]);
            }
            copy(&ops[j], &tmp);
        }
    }
}

void quickSort(int l, int r){
    if(r - l < 10){
        insertSort(l, r);
    }else{
        int rawL = l, rawR = r;
        int axis = ops[(l + r) / 2].pos;
        r--;
        while(l < r){
            while(ops[r].pos>axis) r--;
            while(ops[l].pos<axis) l++;
            if(l < r) swap(&ops[l++], &ops[r--]);
        }
        while(ops[l].pos < axis) l++;

        quickSort(rawL, l);
        quickSort(l, rawR);
    }
}

int binarySearchH(int l, int r, int pos){
    int mid = (l + r) / 2;
    while(l < r){
        mid = (l + r) / 2;
        if(ops[mid].pos < pos){
            l = mid + 1;
        }
        else if(ops[mid].pos > pos){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    if(ops[l].pos > pos){
        return l-1;
    }
    return l;
}

int main(){
    int n, m, opsNum = 0;
    scanf("%d %d", &n, &m);

    int x, c;
    while(n--){
        scanf("%d %d", &x, &c);
        ops[opsNum].pos = x;
        ops[opsNum].val += c;
        opsNum++;
    }

    quickSort(0, opsNum);

    ll tot = 0;
    for(int i = 0; i < opsNum; i++){
        tot += ops[i].val;
        ops[i].val = tot;
    }

    int l, r;
    while(m--){
        scanf("%d %d", &l, &r);
        int next2l = binarySearchH(0, opsNum, l - 1);
        int next2r = binarySearchH(0, opsNum, r);
        if(next2l == opsNum) next2l--;
        if(next2r == opsNum) next2r--;
        printf("%d\n", ops[next2r].val - ops[next2l].val);
    }
}
