#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

#define MAX 1010

using namespace std;

string str[MAX];

int eureka(int mx, int n, string &tar){
    int dp[12][12];
    int rst = 0;

    for(int k = 0; k < n; k++){
        for(int i = 0; i <= max(int(str[k].size()), int(tar.size())); i++){
            dp[i][0] = i;
            dp[0][i] = i;
        }
        for(int i = 0; i < str[k].size(); i++)
            for(int j = 0; j < tar.size(); j++){
                dp[i + 1][j + 1] = min(dp[i + 1][j] + 1, dp[i][j + 1] + 1);
                dp[i + 1][j + 1] = min(dp[i][j] + 1, dp[i + 1][j + 1]);
                if(str[k][i] == tar[j]) dp[i + 1][j + 1] = min(dp[i][j], dp[i + 1][j + 1]);
            }
        if(dp[str[k].size()][tar.size()] <= mx) rst++;
    }

    return rst;
};

int main(){
    int n, m;

    scanf("%d %d", &n ,&m);
    for(int i = 0; i < n; i++)
        cin >> str[i];

    string tar;
    int max;
    while(m--){
        cin >> tar;
        scanf("%d", &max);
        printf("%d\n", eureka(max, n, tar));
    }
}