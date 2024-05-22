#include <stdio.h>
#include <stdlib.h>

#define MAX 100010

int hash(int val){
    return val > 0 ? val % MAX : -val % MAX;
}

struct Node{
    int val;
    struct Node *next;
};

struct Node NONE;

struct Node hashSet[MAX];

void insert(int val){
    int pos = hash(val);
    if(hashSet[pos].next == NULL){
        hashSet[pos].val = val;
        hashSet[pos].next = &NONE;
    }
    else{
        struct Node *tra = &hashSet[pos];
        while(tra->next != &NONE) tra = tra->next;
        tra->next = (struct Node *) malloc(sizeof(struct Node));
        tra = tra->next;
        tra->val = val;
        tra->next = &NONE;
    }
}

int query(int val){
    int pos = hash(val);
    if(hashSet[pos].next == NULL) return 0;
    struct Node * tra = &hashSet[pos];
    while(tra != &NONE){
        if(tra->val == val) return 1;
        else tra = tra->next;
    }
    return 0;
}

int main(){
    for(int i = 0; i < MAX; i++)
        hashSet[i].next = NULL;

    int n;
    scanf("%d", &n);

    char op[5];
    int p;
    while(n--){
        scanf("%s %d", op, &p);
        if(op[0] == 'I') insert(p);
        else if(op[0] == 'Q')
            printf("%s\n", query(p) ? "Yes" : "No");
    }
}