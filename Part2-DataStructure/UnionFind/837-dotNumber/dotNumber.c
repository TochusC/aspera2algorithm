#include <stdio.h>

#define MAX 100010

int uni[MAX];

int findPar(int elm){
    if(uni[elm] < 0)
        return elm;
    else{
        int root = elm;
        while(uni[root] > 0) root = uni[root];
        while(uni[elm] != root){
            int next = uni[elm];
            uni[elm] = root;
            elm = next;
        }
        return root;
    }
}

int findSetSize(int val){
    return -uni[findPar(val)];
}

void merge(int elmA, int elmB){
    elmA = findPar(elmA);
    elmB = findPar(elmB);
    if(elmA != elmB){
        uni[elmA] += uni[elmB];
        uni[elmB] = elmA;
    }
}

int query(int elmA, int elmB){
    return findPar(elmA) == findPar(elmB);
}

int main(){
    for(int i = 0; i < MAX; i++)
        uni[i] = -1;

    int n, m;
    scanf("%d %d", &n, &m);

    char op[5];
    int p1, p2;
    while(m--){
        scanf("%s", op);
        scanf("%d", &p1);

        if(op[0] == 'C'){
            scanf("%d", &p2);
            merge(p1, p2);
        }
        else
            if(op[1] == '1'){
                scanf("%d", &p2);
                printf("%s\n", query(p1, p2) ? "Yes" : "No");
            }
            else
                printf("%d\n", findSetSize(p1));
    }

//    for(int i = 1; i <= n; i++)
//        printf("%d ", uni[i]);
}