#include <cstdio>
#include <utility>
#include <algorithm>

#define NMAX 110
#define VMAX 110

using namespace std;


int dp[NMAX];

int main(){
    int n, v;
    scanf("%d %d", &n, &v);

    int vol, val, num;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &vol, &val, &num);
        for(int t = 0; t < num; t++)
            for(int j = v; j >= vol; j--)
                dp[j] = max(dp[j], dp[j - vol] + val);
    }

    printf("%d", dp[v]);
}