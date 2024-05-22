#include <stdio.h>

#define MAX 100010

int heap[MAX];
int num = 1;

void siftUp(int index){
    int par = index / 2;
    if(!par || heap[par] < heap[index]) return;

    int tmp = heap[index];
    heap[index] = heap[par];
    heap[par] = tmp;

    siftUp(par);
}

void siftDown(int index){
    int lChild = index * 2;
    int rChild = index * 2 + 1;
    int smallChild;

    if(lChild > num - 1) return;
    if(rChild > num - 1) smallChild = lChild;
    else smallChild = heap[lChild] < heap[rChild] ? lChild : rChild;

    if(heap[smallChild] > heap[index]) return;
    int tmpVal = heap[index];
    heap[index] = heap[smallChild];
    heap[smallChild] = tmpVal;

    siftDown(smallChild);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int val;
    while(n--){
        scanf("%d", &val);
        heap[num] = val;
        siftUp(num++);
    }

    while(m--){
        printf("%d ", heap[1]);
        heap[1] = heap[--num];
        siftDown(1);
    }
}