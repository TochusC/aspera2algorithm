#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100010

typedef long long ll;

int gArr[MAX];
ll count;

void mergeSort(int *arr, int size){
    if(size > 1){
        int lSize = size / 2;
        int rSize = size - lSize;

        int *leftArr = (int *) malloc(sizeof(int) * lSize);
        for(int index = 0; index < lSize; index++){
            leftArr[index] = arr[index];
        }
        mergeSort(leftArr, lSize);

        int *rightArr = (int *) malloc(sizeof(int) * (rSize));
        for(int index = 0; index < rSize; index++){
            rightArr[index] = arr[lSize + index];
        }
        mergeSort(rightArr, rSize);

        int lPtr = 0, rPtr = 0, index = 0;

        while(lPtr < lSize && rPtr < rSize){
            if(leftArr[lPtr] > rightArr[rPtr]){
                arr[index++] = rightArr[rPtr++];
                count += lSize - lPtr;
            }
            else{
                arr[index++] = leftArr[lPtr++];
            }
        }

        while(lPtr < lSize){
            arr[index++] = leftArr[lPtr++];
        }
        while(rPtr < rSize){
            arr[index++] = rightArr[rPtr++];
        }
    }
    else{
        return;
    }
}

int main(){
    int size;
    scanf("%d", &size);

    for(int index = 0; index < size; index++){
        scanf("%d", &gArr[index]);
    }

    mergeSort(gArr, size);

    printf("%lld", count);
}