#include <cstdio>
#include <algorithm>

#define N 510
#define INF 1e9

using namespace std;

int dp[N];
int bk[N];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i <= n; i++){
        dp[i] = -INF;
        bk[i] = -INF;
    }
    int num;
    scanf("%d", &num);
    dp[1] = num;
    for(int i = 2; i <= n; i++){
        for(int k = 1; k <= n; k++)
            bk[k] = dp[k];
        for(int j = 1; j <= n; j++){
            if(j <= i) scanf("%d", &num);
            else num = 0;
            dp[j] = max(bk[j] + num, bk[j-1] + num);
        }

    }

    int rst = -INF;
    for(int k = 1; k <= n; k++)
        rst = max(rst, dp[k]);

    printf("%d", rst);
}