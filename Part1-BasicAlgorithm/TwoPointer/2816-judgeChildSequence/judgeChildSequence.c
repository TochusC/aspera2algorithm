#include <stdio.h>

#define MAX 100010

int a[MAX], b[MAX];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &b[i]);
    }

    int p1 = 0, p2 = 0;
    while(p1 <  n&& p2 < m){
        if(b[p2] == a[p1]){
            p2++;
            p1++;
        }
        else{
            p2++;
        }
    }
    if(p1 == n){
        printf("Yes");
    }
    else printf("No");
}