#include <stdio.h>
#include <stdlib.h>

#define MAX 100010

int stack[MAX];
int top = 0;

int strcmp(char *a, char*b){
    while(*a != '\0' && *b != '\0'){
        if(*a != *b){
            return 0;
        }
        a++; b++;
    }
    if(*a == '\0' && *b == '\0'){
        return 1;
    }
    else return 0;
}

int main(){
    int m;
    scanf("%d" , &m);
    char op[10];
    int p;
    while(m--){
        scanf("%s", op);

        if(strcmp(op, "push")){
            scanf("%d", &p);
            stack[top++] = p;
        }
        else if(strcmp(op, "query"))
            printf("%d\n", stack[top-1]);
        else if(strcmp(op, "pop")) top--;
        else if(strcmp(op, "empty"))
            printf("%s\n", top == 0 ? "YES" : "NO");
    }
}