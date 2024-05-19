#include <stdio.h>
#include <stdlib.h>

#define MAX 100010

typedef struct{
    int l, r;
} Range;

Range ranArr[MAX];

int main(){
    int n;
    scanf("%d", &n);

    int arrLen = 0;
    int i, l, r;
    int needCheck = 0;
    while(n--){
        scanf("%d %d", &l, &r);
        for(i = 0; i < arrLen; i++){
            // 相交A
            if(ranArr[i].r >= l && ranArr[i].l <= l){
                // 旧包含新
                if(ranArr[i].l <= l && ranArr[i].r >= r){}
                // 新包含旧
                else if(ranArr[i].l >= l && ranArr[i].r <= r){
                    ranArr[i].l = l;
                    ranArr[i].r = r;
                }
                // 单纯相交
                else{
                    ranArr[i].r = ranArr[i].r > r ? ranArr[i].r : r;
                }
                break;
            }
            // 相交B
            else if(ranArr[i].l <= r && ranArr[i].r >= r){
                // 旧包含新
                if(ranArr[i].l <= l && ranArr[i].r >= r){}
                // 新包含旧
                else if(ranArr[i].l >= l && ranArr[i].r <= r){
                    ranArr[i].l = l;
                    ranArr[i].r = r;
                }
                // 单纯相交
                else{
                    ranArr[i].l = ranArr[i].l < l ? ranArr[i].l : l;
                }
                break;
            }

        }
        if(i == arrLen){
            ranArr[arrLen].l = l;
            ranArr[arrLen].r = r;
            arrLen++;
        }
    }
    printf("%d", arrLen);
}