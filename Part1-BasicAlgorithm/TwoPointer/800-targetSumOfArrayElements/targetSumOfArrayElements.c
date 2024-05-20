#include <stdio.h>

#define MAX 100010

typedef long long ll;

int arrA[MAX], arrB[MAX];

int main(){
    int sizeOfA, sizeOfB, tar;
    scanf("%d %d %d", &sizeOfA, &sizeOfB, &tar);

    for(int i = 0; i < sizeOfA; i++)
        scanf("%d", &arrA[i]);


    for(int i = 0; i < sizeOfB; i++)
        scanf("%d", &arrB[i]);

    int ptr1 = 0, ptr2 = 0, sum;
    int aInc, bInc;

    while(ptr1 < sizeOfA && ptr2 < sizeOfB){
        sum = arrA[ptr1] + arrB[ptr2];
        if(sum < tar){
            if(ptr2 + 1 == sizeOfB)
                ptr1++;
            else
                ptr2++;
        }
        else if(sum > tar){
            ptr1++;
            while(sum > tar){
                ptr2--;
                sum = arrA[ptr1] + arrB[ptr2];
            }
        }
        else{
            break;
        }
    }
    printf("%d %d", ptr1, ptr2);
}
