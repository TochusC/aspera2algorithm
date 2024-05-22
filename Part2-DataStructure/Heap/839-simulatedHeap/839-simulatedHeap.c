#include <stdio.h>

#define MAX 100010

struct Num{
    int val;
    int pos;
};

struct Num num[MAX];
int len = 1;

int hp[MAX];
int sz = 1;

void siftUp(int ind){
    int par = ind / 2;
    if(!par || num[hp[par]].val < num[hp[ind]].val) return;

    int tmpNum = hp[ind];
    num[hp[ind]].pos = par;
    hp[ind] = hp[par];
    num[hp[par]].pos = ind;
    hp[par] = tmpNum;

    siftUp(par);
}

void siftDown(int ind){
    int lCh = ind * 2, rCh = lCh + 1;
    int sCh;
    if(lCh > sz - 1) return;

    if(rCh > sz - 1) sCh = lCh;
    else sCh = num[hp[lCh]].val < num[hp[rCh]].val ? lCh : rCh;

    if(num[hp[ind]].val < num[hp[sCh]].val) return;

    int tmp = hp[ind];
    num[hp[ind]].pos = sCh;
    hp[ind] = hp[sCh];
    num[hp[sCh]].pos = ind;
    hp[sCh] = tmp;

    siftDown(sCh);
}

void insert(int val){
    num[len].val = val;
    num[len].pos = sz;
    hp[sz] = len++;
    siftUp(sz++);
}

int peek(){
    return num[hp[1]].val;
}

int pop(){
    int rst = num[hp[1]].val;
    num[hp[1]].pos = -1;
    hp[1] = hp[--sz];
    num[hp[sz]].pos = 1;
    siftDown(1);
    return rst;
}

void del(int ind){
    int pos = num[ind].pos;
    num[ind].pos = -1;

    hp[pos] = hp[--sz];
    num[hp[pos]].pos = pos;

    if(pos == -1 || pos == sz) return;
    siftDown(pos);
    siftUp(pos);
}

void alt(int ind, int val){
    num[ind].val = val;
    int pos = num[ind].pos;

    if(pos == -1) return;
    siftDown(pos);
    siftUp(pos);
}

int main(){
    int n;
    scanf("%d", &n);

    char op[5];
    int p1, p2;
    while(n--){
        scanf("%s", op);
        if(op[0] == 'I'){
            scanf("%d", &p1);
            insert(p1);
        }
        else if(op[0] == 'P') printf("%d\n", peek());
        else if(op[0] == 'D'){
            if(op[1] == '\0'){
                scanf("%d", &p1);
                del(p1);
            }
            else pop();
        }
        else if(op[0] == 'C'){
            scanf("%d %d", &p1, &p2);
            alt(p1, p2);
        }
    }
}