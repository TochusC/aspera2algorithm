#include <stdio.h>

#define MAX 50010

int uni[MAX * 3];

int findPar(int val){
    if(uni[val] == -1)
        return val;
    int root = uni[val];
    while(uni[root] != -1) root = uni[root];
    while(uni[val] != root){
        int next = uni[val];
        uni[val] = root;
        val = next;
    }
    return root;
}

void merge(int elmA, int elmB){
    elmA = findPar(elmA);
    elmB = findPar(elmB);
    if(elmA != elmB) uni[elmB] = elmA;
}

int same(int elmA, int elmB){
    return findPar(elmA) == findPar(elmB);
}

int mentioned[MAX];

int main(){
    for(int i = 0; i < MAX * 3; i++)
        uni[i] = -1;

    for(int i = 0; i < MAX; i++)
        mentioned[i] = 0;

    int n, k;
    scanf("%d %d", &n, &k);

    int ans = 0;
    int type, elm1, elm2;
    while(k--){
        scanf("%d %d %d", &type, &elm1, &elm2);
        if(elm1 > n || elm2 > n){
            ans++;
            continue;
        }
        if(type == 1){
            if(mentioned[elm1] && mentioned[elm2]) {
                if (elm1 > n || elm2 > n || same(elm1, elm2 * 2) || same(elm1, elm2 * 3)) {
                    ans++;
                } else {
                    merge(elm1, elm2);
                    merge(elm1 * 2, elm2 * 2);
                    merge(elm1 * 3, elm2 * 3);
                }
            }
            else{
                mentioned[elm1] = 1;
                mentioned[elm2] = 1;
                merge(elm1, elm2);
                merge(elm1 * 2, elm2 * 2);
                merge(elm1 * 3, elm2 * 3);
            }
        }
        else{
            if(mentioned[elm1] && mentioned[elm2]) {
                if(elm1 == elm2 || same(elm1, elm2)){
                    ans++;
                }
                else{
                    merge(elm1, elm2 *2);
                    merge(elm1 * 2, elm2 * 3);
                    merge(elm1 * 3, elm2);
                }
            }
            else{
                mentioned[elm1] = 1;
                mentioned[elm2] = 1;
                merge(elm1, elm2 *2);
                merge(elm1 * 2, elm2 * 3);
                merge(elm1 * 3, elm2);
            }

        }
    }

    printf("%d", ans);
}