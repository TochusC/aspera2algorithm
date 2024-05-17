#include <stdio.h>

#define MAX 100010

int arr[MAX];

int binarySearch_L(int *arr, int size, int tar){
    int l = 0, r = size;

    while(l < r){
        int mid = (l + r)/2;
        if(arr[mid] < tar){
            l = mid + 1;
        }
        else if(arr[mid] > tar){
            r = mid;
        }
        else{
            r = mid;
        }
    }
    if(arr[l] == tar){
        return l;
    }
    else{
        return -1;
    }
}
int binarySearch_H(int *arr, int size, int tar){
    int l = 0, r = size;

    while(l < r){
        int mid = (l + r)/2;
        if(arr[mid] < tar){
            l = mid + 1;
        }
        else if(arr[mid] > tar){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    if(arr[l - 1] == tar){
        return l - 1;
    }
    else{
        return -1;
    }
}

int main(){
    int size, times;
    scanf("%d %d", &size, &times);

    for(int index = 0; index < size; index++){
        scanf("%d", &arr[index]);
    }

    int queryNumber;

    while(times--){
        scanf("%d", &queryNumber);
        int lPos = binarySearch_L(arr, size, queryNumber);
        int hPos = -1;
        if(lPos != -1){
            hPos = binarySearch_H(arr, size, queryNumber);
        }
        printf("%d %d\n", lPos, hPos);
    }

}