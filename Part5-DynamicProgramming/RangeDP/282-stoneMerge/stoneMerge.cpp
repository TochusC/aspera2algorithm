#include <cstdio>
#include <algorithm>

#define MAX 330
#define INF 1e9

using namespace std;

int mas[MAX];
int dp[MAX][MAX];
int cost[MAX][MAX];

int eureka(int l, int r){
    int rst = dp[l][r];

    int bk = rst;
    for(int i = l; i < r; i++){
        if(dp[l][i] + dp[i + 1][r] == dp[l][r]){
            if(bk != rst)
                rst = min(rst, bk + eureka(l, i) + eureka(i + 1, r));
            else rst = rst + eureka(l, i) + eureka(i + 1, r);
        }
    }
    if(r == l) rst = 0;

    return rst;
}

int  main(){
    int num;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++)
        for(int j = 1; j <= num; j++){
            dp[i][j] = INF;
            cost[i][j] = INF;
        }

    for(int i = 1; i <= num; i++){
        scanf("%d", &dp[i][i]);
        cost[i][i] = 0;
    }

    for(int k = 1; k < num; k++)
        for (int i = 1; i + k <= num; i++)
            for (int j = 0; j < k; j++) {
                    if(dp[i][i + j] + dp[i + j + 1][i + k] <= dp[i][i + k]){
                        dp[i][i + k] = dp[i][i + j] + dp[i + j + 1][i + k];
                        cost[i][i + k] = min(cost[i][i + k], dp[i][i + k] + cost[i][i + j] + cost[i + j + 1][i + k]);
                    }
                }

    printf("%d", cost[1][num]);
}