#include <cstdio>
#include <utility>
#include <algorithm>

#define NMAX 1010
#define VMAX 1010

using namespace std;

typedef pair<int, int> PII;
PII item[NMAX];

int dp[VMAX];
int main(){
    int n, v;
    scanf("%d %d", &n, &v);

    for(int i = 0; i <n; i++){
        scanf("%d %d", &item[i].first, &item[i].second);
        for(int j = v; j >= item[i].first; j--)
            dp[j] = max(dp[j], dp[j - item[i].first] + item[i].second);
    }

    printf("%d", dp[v]);
}