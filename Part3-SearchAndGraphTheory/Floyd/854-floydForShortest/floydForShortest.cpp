#include <cstdio>
#include <vector>
#include <utility>

#define NMAX 210
#define INF 1e8

using namespace std;

typedef pair<int, int> PII;

int dp[NMAX][NMAX];

int main(){
    int n, m ,k;
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = INF;

    for(int i = 1; i <= n; i++)
            dp[i][i] = 0;

    int from, to, wig;
    while(m--){
        scanf("%d %d %d", &from, &to, &wig);
        dp[from][to] = min(dp[from][to], wig);
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                if(dp[i][k] == INF || dp[k][j] == INF) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }

    while(k--){
        scanf("%d %d", &from, &to);
        if(dp[from][to] == INF) printf("impossible\n");
        else printf("%d\n", dp[from][to]);
    }
}