//
// Created by 20532 on 2024/5/18.
//
#include <stdio.h>

#define MAX 100010

typedef long long ll;

int arr[MAX];
ll sumArr[MAX];

int main(){
    int arrLen, queryNum;
    scanf("%d %d", &arrLen, &queryNum);

    int val;
    sumArr[0] = 0;
    for(int index = 0; index < arrLen; index++){
        scanf("%d", &val);
        arr[index] = val;
        sumArr[index + 1] = sumArr[index] + val;
    }
    int lBoundary, rBoundary;
    while(queryNum--){
        scanf("%d %d", &lBoundary, &rBoundary);
        printf("%lld\n", sumArr[rBoundary] - sumArr[lBoundary - 1]);
    }

}