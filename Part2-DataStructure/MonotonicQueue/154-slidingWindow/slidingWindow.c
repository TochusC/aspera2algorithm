#include <stdio.h>

#define MAX 1000010

int arr[MAX];

struct Queue{
    int elms[MAX];
    int head, tail;
};

void push(struct Queue *que, int val){
    que->elms[que->tail++] =  val;
}

int pop_back(struct Queue *que){
    return que->elms[--que->tail];
}

int pop_front(struct Queue *que){
    return que->elms[que->head++];
}

int back(struct Queue *que){
    return que->elms[que->tail - 1];
}

int front(struct Queue *que){
    return que->elms[que->head];
}

int empty(struct Queue *que){
    return que->head == que->tail;
}

int size(struct Queue *que){
    return que->tail - que->head;
}

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    struct Queue que;
    que.head = 0;
    que.tail = 0;

    struct Queue que2;
    que2.head = 0;
    que2.tail = 0;

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++){
        while(!empty(&que) && arr[back(&que)] >= arr[i] ) pop_back(&que);
        push(&que, i);
        if(!empty(&que) && i - k == front(&que))
            pop_front(&que);
        if(i + 1 >= k)
            printf("%d ", arr[front(&que)]);
    }

    printf("\n");

    for(int i = 0; i < n; i++){
        while(!empty(&que2) && arr[back(&que2)] <= arr[i] ) pop_back(&que2);
        push(&que2, i);
        if(!empty(&que2) && i - k == front(&que2))
            pop_front(&que2);
        if(i + 1 >= k)
            printf("%d ", arr[front(&que2)]);
    }
}