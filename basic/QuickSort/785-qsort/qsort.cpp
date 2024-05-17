# include <cstdio>


#define MAX 100000 + 10

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


int arr[MAX];

void qsort(int *arr, int size){
    int l = 0;
    int r = size - 1;

    if(r < 1)
        return;

    int pivot = arr[size >> 1];

    while(l < r){
        while(arr[l] < pivot)
            l++;
        while(pivot < arr[r])
            r--;
        if(l < r){
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }

    while(arr[l] < pivot)
        l++;

    qsort(arr, l);
    qsort(arr + l, size - l);
}


int main(){
    int num;
    scanf("%d", &num);

    for(int index = 0; index < num; index++){
        scanf("%d", &arr[index]);
    }

    qsort(arr, num);

    for(int i = 0; i < num; i++)
        printf("%d ", arr[i]);
}