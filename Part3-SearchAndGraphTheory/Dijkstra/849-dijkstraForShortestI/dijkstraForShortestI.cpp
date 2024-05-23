#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define INF 1e5
#define NMAX 510
#define MMAX 100010

using namespace std;

int dis[NMAX];
bool vis[NMAX];
vector<pair<int, int>>eg[NMAX];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int from, to, wig;
    while(m--){
        scanf("%d %d %d", &from, &to, &wig);
        eg[from].emplace_back(to, wig);
    }

    for(auto &i : dis)
        i = INF;

    int next = 1;
    dis[1] = 0;

    int mist = INF;
    while(next != -1){
        mist = INF;
        vis[next] = true;
        for(auto e: eg[next])
            dis[e.first] = min(dis[next] + e.second, dis[e.first]);
        next = -1;
        for(int i = 1; i <= n; i++)
            if(!vis[i] && dis[i] < mist){
                next = i;
                mist = dis[i];
            }
    }

    printf("%d", dis[n] == INF ? -1 : dis[n]);
}
