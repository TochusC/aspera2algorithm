#include <stdio.h>

#define MAX 100010

int arr[MAX];
int visit[MAX];

int main(){
    int len;
    scanf("%d", &len);

    for(int index = 0; index < len; index++){
        scanf("%d", &arr[index]);
    }

    int bst = 0;
    int rst = 0;
    int ptr1 = 0, ptr2 = 0;
    while(ptr2 < len){
        if(visit[arr[ptr2]] == 0){
            rst++;
            if(rst > bst){
                bst = rst;
            }
            visit[arr[ptr2++]] = 1;
        }
        else{
            rst--;
            visit[arr[ptr1++]] = 0;
        }
    }

    printf("%d", bst);
}