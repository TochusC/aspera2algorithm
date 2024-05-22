#include <stdio.h>
#include <stdlib.h>

#define MAX 100010

typedef struct{
    int l, r;
} Range;

Range ranArr[MAX];

void swap(Range *a, Range *b){
    int tmpL = a->l;
    int tmpR = a->r;

    a->l = b->l;
    a->r = b->r;

    b->l = tmpL;
    b->r = tmpR;
}

void copy(Range *a, Range *b){
    a->l = b->l;
    a->r = b->r;
}

void insertSort(int l, int r){
    for(int i = l + 1; i < r; i++){
        if(ranArr[i].l < ranArr[i - 1].l){
            int j = i - 1;

            while(ranArr[i].l < ranArr[j - 1].l && j - 1 > l) j--;

            int tmpL = ranArr[i].l;
            int tmpR = ranArr[i].r;

            for(int t = i; t > j; t--){
                ranArr[t].l = ranArr[t-1].l;
                ranArr[t].r = ranArr[t-1].r;
            }

            ranArr[j].l = tmpL;
            ranArr[j].r = tmpR;
        }
    }
}

void quickSort(int l, int r){
    if(r - l < 10){
        insertSort(l, r);
    }
    else{
        int pivot = ranArr[(l + r) / 2].l;
        int tl = l, tr = r;
        while(tl < tr){
            while(ranArr[tl].l < pivot) tl++;
            while(ranArr[tr].l > pivot) tr--;
            if(tl < tr) swap(&ranArr[tl++], &ranArr[tr--]);
        }
        while(ranArr[tl].l < pivot) tl++;
        quickSort(l, tl);
        quickSort(tl, r);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int arrLen = 0;
    int i, l, r;
    int needCheck = 0;
    while(n--){
        scanf("%d %d", &l, &r);
        for(i = 0; i < arrLen; i++){
            // 相交A
            if(ranArr[i].r >= l && ranArr[i].l <= l){
                // 旧包含新
                if(ranArr[i].l <= l && ranArr[i].r >= r){}
                    // 新包含旧
                else if(ranArr[i].l >= l && ranArr[i].r <= r){
                    ranArr[i].l = l;
                    ranArr[i].r = r;
                }
                    // 单纯相交
                else{
                    ranArr[i].r = ranArr[i].r > r ? ranArr[i].r : r;
                }
                break;
            }
                // 相交B
            else if(ranArr[i].l <= r && ranArr[i].r >= r){
                // 旧包含新
                if(ranArr[i].l <= l && ranArr[i].r >= r){}
                    // 新包含旧
                else if(ranArr[i].l >= l && ranArr[i].r <= r){
                    ranArr[i].l = l;
                    ranArr[i].r = r;
                }
                    // 单纯相交
                else{
                    ranArr[i].l = ranArr[i].l < l ? ranArr[i].l : l;
                }
                break;
            }

        }
        if(i == arrLen){
            ranArr[arrLen].l = l;
            ranArr[arrLen].r = r;
            arrLen++;
        }
    }

    quickSort(0, arrLen);

    int prevR = ranArr[0].r;
    int rst = 1;
    for(int index = 1; index < arrLen; index++){
        if(ranArr[index].l > prevR){
            rst++;
            prevR = ranArr[index].r;
        }
        else{
            if(ranArr[index].r > prevR){
                prevR = ranArr[index].r;
            }
        }
    }

    printf("%d", rst);
}