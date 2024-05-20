#include <stdio.h>

#define MAX 100010

struct Queue{
    int elms[MAX];
    int head, tail;
};

void push(struct Queue *que, int val){
    que->elms[que->tail++] = val;
}

int empty(struct Queue *que){
    return que->head == que->tail;
}

int pop(struct Queue *que){
    return que->elms[que->head++];
}

int query(struct Queue *que){
    return que->elms[que->head];
}

int strcmp(char *a, char *b){
    while(*a != '\0' && *b != '\0'){
        if(*a != *b) return 0;
        a++; b++;
    }
    if(*a != '\0' || *b != '\0') return 0;
    else return 1;
}

int main(){
    struct Queue que;
    que.head = 0;
    que.tail = 0;

    int m;
    scanf("%d", &m);

    int p;
    char op[5];
    while(m--){
        scanf("%s", op);
        if(strcmp(op, "push")){
            scanf("%d", &p);
            push(&que, p);
        }
        else if(strcmp(op, "empty")){
            if(empty(&que)) printf("YES\n");
            else printf("NO\n");
        }
        else if(strcmp(op, "pop")) pop(&que);
        else if(strcmp(op, "query")) printf("%d\n", query(&que));
    }
}