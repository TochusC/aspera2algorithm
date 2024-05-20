#include <cstdio>

#define MAX 100010

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int arr[MAX];

void qSelect(int *arr, int l, int r, int k){
    int rawL = l;
    int rawR = r;
    int pivot = arr[( l + r )/ 2];
    r-=1;

    if(r < l + 1 || k < l) return;

    while(l < r){
        while(arr[l] < pivot) l++;
        while(pivot < arr[r]) r--;
        if(l < r) swap(arr[l++], arr[r--]);
    }

    while(arr[l] < pivot) l++;

    qSelect(arr, rawL, l, k);
    qSelect(arr, l, rawR, k);
}

int main(){
    int s, k;
    scanf("%d %d\n", &s, &k);

    for(int i = 0; i < s; i++){
        scanf("%d", &arr[i]);
    }

    qSelect(arr, 0, s, k-1);

    printf("%d", arr[k-1]);
}