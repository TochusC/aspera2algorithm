#include <cstdio>
#include <algorithm>

#define MAX 1010

using namespace std;

char strA[MAX];
char strB[MAX];

int dp[MAX][MAX];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", strA);
    scanf("%s", strB);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            dp[i + 1][j + 1] = max(max(max(dp[i + 1][j + 1], dp[i + 1][j]), dp[i][j + 1]), dp[i][j]);
            if(strA[i] == strB[j]) dp[i + 1][j + 1] = max(dp[i][j] + 1, dp[i + 1][j + 1]);
        }
    printf("%d", dp[n][m]);
}