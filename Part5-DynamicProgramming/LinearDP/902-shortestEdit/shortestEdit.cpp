#include <cstdio>
#include <algorithm>

#define MAX 1010
#define INF 1e9

using namespace std;

char strA[MAX], strB[MAX];
int dp[MAX][MAX];

int main(){
    int n, m;

    scanf("%d", &n);
    scanf("%s", strA);

    scanf("%d", &m);
    scanf("%s", strB);

    for(int i = 0; i <= max(n, m); i++){
        dp[i][0] = i;
        dp[0][i] = i;
    }
    dp[0][0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // 插入、删除操作
            dp[i + 1][j + 1] = min(dp[i + 1][j] + 1, dp[i][j + 1] + 1);
            // 替换操作
            dp[i + 1][j + 1] = min(dp[i][j] + 1, dp[i + 1][j + 1]);
            // 相等
            if(strA[i] == strB[j])
                dp[i + 1][j + 1] = min(dp[i][j], dp[i + 1][j + 1]);
        }
    }

    printf("%d\n", dp[n][m]);
}