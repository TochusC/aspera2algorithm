#include <stdio.h>
#include <stdlib.h>

#define MAX 100010

struct Range{
    int l, r;
};

struct Range ran[MAX];
int num = 0;

int cmp(void *a, void *b){
    struct Range* ra = (struct Range*) a;
    struct Range* rb = (struct Range*) b;
    return ra -> l < rb -> l;
}

void swap(struct Range *a, struct Range *b){
    struct Range tmp;
    tmp.l = a->l; tmp.r = a->r;
    a->l = b->l; a->r = b->r;
    b->l = tmp.l; b->r = tmp.r;
}

void copy(void *dest, void *src, size_t size) {
    while (size--)
        *(char*)(dest++) = *(char*)(src++);
}

void insertSort(void *arr, size_t size, int l, int r, int (*cmp)(void *a, void *b)){
    for(int i = l + 1; i < r; i++)
        for(int j = i; j - 1 >= l && cmp(arr + j * size, arr + (j - 1) * size); j--)
            swap(arr + j * size, arr + (j - 1) * size);
}

void quickSort(void *arr, size_t size, int l, int r, int (*cmp)(void *a, void *b)){
    if(r - l < 3) insertSort(arr, size, l, r, cmp);
    else{
        void *pivot = malloc(size);
        copy(pivot, arr + ((l + r ) /2) * size, size);

        int tl = l, tr = r - 1;
        while(tl < tr){
            while(cmp(arr + tl * size, pivot)) tl++;
            while(cmp(pivot, arr + tr * size)) tr--;
            if(tl < tr)
                swap(arr + tl++ * size, arr + tr-- * size);
        }

        while(cmp(arr + tl * size, pivot)) tl++;
        quickSort(arr, size, l, tl, cmp);
        quickSort(arr, size, tl, r, cmp);
    }
}

int max(int a, int b){
    return a > b ? a : b;
}

int merge(struct Range *arr, int num){
    int prevR = arr[0].r;
    int gap = 0;

    for(int i = 1; i < num; i++){
        if(arr[i].l <= prevR){
            gap++;
            arr[i].r = max(arr[i - gap].r, arr[i].r);
        }
        prevR = arr[i].r;
        arr[i - gap].r = arr[i].r;
    }
   return num - gap;
}

int main(){
    int n;
    scanf("%d", &n);

    int l, r;
    while(n--){
        scanf("%d %d", &l, &r);
        ran[num].l = l;
        ran[num++].r = r;
    }


    quickSort(ran, sizeof(struct Range), 0, num, cmp);
    printf("%d\n", merge(ran, num));
}