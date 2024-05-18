#include <stdio.h>

#define MAX 100010

int a[MAX];

int main(){
    int n;
    scanf("%d", &n);

    int val, rst;
    while(n--){
        rst = 0;
        scanf("%d", &val);
        while(val){
            if(val & 1){
                rst++;
            }
            val >>= 1;
        }
        printf("%d ", rst);
    }
}