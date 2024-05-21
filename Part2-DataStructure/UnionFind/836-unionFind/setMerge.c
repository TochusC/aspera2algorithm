#include <stdio.h>

#define MAX 100010

int arr[MAX];

int compress(int a){
    int root = a;
    while(arr[root] != -1)
        root = arr[root];

    while(arr[a] != root && arr[a] != -1){
        int tmp = arr[a];
        arr[a] = root;
        a = tmp;
    }
    return root;
}

void merge(int a, int b){
    int parA = compress(a);
    int parB = compress(b);
    if(parA != parB)
    arr[parB] = parA;
}

int query(int a, int b){
    while(arr[a] != -1) a = arr[a];
    while(arr[b] != -1) b = arr[b];
    if(a == b) return 1;
    else return 0;
}

int main(){
    for(int i = 0; i < MAX; i++)
        arr[i] = -1;

    int n, m;
    scanf("%d %d", &n, &m);

    char op[5];
    int p1, p2;
    while(m--){
        scanf("%s %d %d", op, &p1, &p2);
        if(op[0] == 'M') merge(p1, p2);
        else if(op[0] == 'Q')
            printf("%s", query(p1, p2) ? "Yes\n" : "No\n");
    }

//    for(int i = 1; i < n + 1; i++)
//        printf("%d ", arr[i]);
}
