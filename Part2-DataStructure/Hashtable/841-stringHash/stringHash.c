#include <stdio.h>

#define MAX 100010

#define P 131

typedef long long ll;

char str[MAX];

ll hash(char *chr, int size){
    ll rst = 0;
    ll base = P;
    int ind = 0;
    while(ind < size){
        rst += *(chr + ind) * base;
        base *= P;
        ind++;
    }
    return rst;
}


ll p[MAX];
ll base[MAX];


int cmp(int l1, int r1, int l2, int r2){
    ll rstA = p[r1] - p[l1 - 1] * base[r1 - l1 + 1];
    ll rstB = p[r2] - p[l2 - 1] * base[r2 - l2 + 1];

    return rstA == rstB;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", str);

    base[0] = 1;
    p[0] = 0;
    for(int i = 1; i <= n; i++){
        base[i] = base[i - 1] * P;
        p[i] = (p[i - 1] * P + str[i - 1]);
    }

    int l1, l2, r1, r2;
    while(m--){
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        printf("%s\n", cmp(l1, r1, l2, r2) ? "Yes" : "No");
    }
}