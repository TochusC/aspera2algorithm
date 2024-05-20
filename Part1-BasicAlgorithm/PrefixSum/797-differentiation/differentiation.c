#include <stdio.h>

#define MAX 100010

typedef long long ll;

ll difArr[MAX];

int main(){
    int arrLen, queryNum;
    scanf("%d %d", &arrLen, &queryNum);

    ll base = 0;
    int val;
    for(int index = 0; index < arrLen; index++){
        scanf("%d", &val);
        difArr[index] = val - base;
        base = val;
    }

    int l, r, c;
    while(queryNum--){
        scanf("%d %d %d", &l, &r, &c);
        difArr[l - 1] += c;
        difArr[r] -= c;
    }

    base = 0;
    for(int index = 0; index < arrLen; index++){
        base += difArr[index];
        printf("%lld ", base);
    }
}