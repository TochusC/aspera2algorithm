#include <stdio.h>

#define MAX 8

int rst[MAX];
int used[MAX];
int n;

void dfs(int ind){
    if(ind > n){
        for(int i = 1; i <= n; i++) printf("%d ", rst[i]);
        printf("\n");
    }

    for(int i = 1; i <= n; i++){
        if(used[i]) continue;
        used[i] = 1;
        rst[ind] = i;
        dfs(ind + 1);
        used[i] = 0;
    }
}

int main(){
    scanf("%d", &n);
    dfs(1);
}