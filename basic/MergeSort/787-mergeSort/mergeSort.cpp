#include <cstdio>

#define MAX 100010

int arr[MAX];

int* mergeSort(int *arr, int size){
    int mid = size/2;
    int *leftArr, *rightArr;
    if(mid > 1){
        leftArr = mergeSort(arr, mid);
        rightArr = mergeSort(arr + mid, size - mid);
    }
    else{
        leftArr = new int(arr[0]);
        if(size - mid > 1){
            rightArr = mergeSort(arr + mid, size - mid);
        } else{
            rightArr = new int(arr[1]);
        }
    }

    int lptr = 0, rptr = 0;
    int *rstArr = new int[size];

    for(int index = 0; lptr < mid || rptr < size - mid; index++){
        if(lptr < mid){
            if(rptr < size - mid){
                if(rightArr[rptr] > leftArr[lptr]){
                    rstArr[index] = leftArr[lptr++];
                }
                else{

                    rstArr[index] = rightArr[rptr++];
                }
            }
            else{
                rstArr[index] = leftArr[lptr++];
            }
        }
        else{
            rstArr[index] = rightArr[rptr++];
        }
    }

    delete leftArr;
    delete rightArr;
    return rstArr;
}

int main(){
    int size;
    scanf("%d", &size);

    for(int index = 0; index < size; index++){
        scanf("%d", &arr[index]);
    }

    int *rstArr = mergeSort(arr, size);

    for(int index = 0; index < size; index++){
        printf("%d ", rstArr[index]);
    }
}