#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

#define NMAX 550

using namespace std;

typedef pair<int, int> PII;

vector<PII> eg[NMAX];
bool in[NMAX];
priority_queue<PII, vector<PII>, greater<PII>> que;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int from, to, wig;
    while(m--){
        scanf("%d %d %d", &from, &to, &wig);
        eg[from].emplace_back(to, wig);
        eg[to].emplace_back(from, wig);
    }

    int ans = 0;
    que.emplace(0, 1);
    while(!que.empty()){
        auto pr = que.top();
        que.pop();

        int wig = pr.first;
        int nd = pr.second;

        if(in[nd]) continue;
        else in[nd] = true;

        ans += wig;

        for(auto &e : eg[nd]){
            if(in[e.first]) continue;
            else que.emplace(e.second, e.first);
        }
    }

    for(int i = 1; i <= n; i++)
        if(!in[i]){
            printf("impossible");
            return 0;
        }
    printf("%d", ans);
    return 0;
}
