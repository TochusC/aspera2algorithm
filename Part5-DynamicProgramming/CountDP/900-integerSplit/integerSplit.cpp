#include <cstdio>

#define MAX 1010
#define MOD int(1e9 + 7)

int n;
int dp[MAX][MAX];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        dp[0][i] = 1;
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i - j >= 0) dp[i][j] = (dp[i][j-1] + dp[i - j][j]) % MOD;
            else dp[i][j] = dp[i][j-1];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = (ans + dp[n - i][i]) % MOD;
    }
    printf("%d", ans);
}