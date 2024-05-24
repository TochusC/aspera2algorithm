#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>

#define NMAX 110
#define SMAX 110

using namespace std;

typedef pair<int, int> PII;

struct Group{
    vector<PII> ims;
};

queue<PII> ims;
int dp[NMAX];
int bk[NMAX];
int ts[NMAX];

int main(){
    int n, v;
    scanf("%d %d", &n, &v);

    int num, vol, val;
    for(int i = 0; i < n; i++){
        scanf("%d", &num);

        for(int j = 0; j <= v; j++){
            bk[j] = dp[j];
            ts[j] = bk[j];
        }

        while(num--){
            scanf("%d %d", &vol, &val);
            ims.emplace(vol, val);
        }

        while(ims.size()){
            auto im = ims.front();
            ims.pop();
            for(int j = v; j >= im.first; j--)
                ts[j] = max(ts[j], ts[j - im.first] + im.second);
            for(int j = 0; j <= v; j++){
                dp[j] = max(ts[j], dp[j]);
                ts[j] = bk[j];
            }
        }
    }
    printf("%d\n", dp[v]);
}