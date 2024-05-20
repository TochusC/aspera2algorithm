#include <stdio.h>

#define MAX 100010

struct Elm{
    int val;
    int pre;
};

struct Elm mon[MAX];
int arr[MAX];

int len = 0;

void sol1(){
    int n;
    scanf("%d", &n);
    int val;

    while(n--){
        scanf("%d", &val);

        int tra = len - 1;
        while(tra != -1 && mon[tra].val >= val)
            tra = mon[tra].pre;

        mon[len].val = val;
        mon[len++].pre = tra;
    }

    for(int i = 0; i < len; i++){
        if(mon[i].pre != -1) printf("%d ", mon[mon[i].pre].val);
        else printf("-1 ");
    }
};

int main(){
    int n;
    scanf("%d", &n);
    int val;

    while(n--) {
        scanf("%d", &val);
        if(len == 0) {
            printf("-1 ");
        }
        else{
            while(len - 1 != -1 && val <= arr[len -1]) len--;
            if (len == 0){
                printf("-1 ");
                len = 0;
            }
            else printf("%d ", arr[len - 1]);
        }
        arr[len++] = val;
    }
}