#include <cstdio>
#include <algorithm>
#include <array>

#define NMAX 100010
#define INF 2e9

using namespace std;

array<int, NMAX> dp;

int main(){
    for(auto &e :dp)
        e = INF;

    int n;
    scanf("%d", &n);

    int num;
    scanf("%d", &num);
    dp[1] = num;

    int rst = 1;
    for(int i = 1; i < n; i++){
        scanf("%d", &num);
        auto low = lower_bound(dp.begin() + 1, dp.begin() + n + 1, num);
        int len = low - dp.begin();
        dp[len] = num;
        rst = max(rst, len);
    }
    printf("%d", rst);
}