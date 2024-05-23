#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

#define NMAX 100010
#define MMAX 100010
#define INF 1e8

using namespace std;

typedef pair<int, int> PII;

vector<PII> eg[NMAX];
queue<int> que, que2;
int dist[NMAX];
bool vis[NMAX];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int from, to, wig;
    while(m--){
        scanf("%d %d %d", &from, &to, &wig);
        eg[from].emplace_back(to, wig);
    }

    for(auto &dis : dist) dis = INF;

    que.push(1);
    vis[1] = true;
    dist[1] = 0;
    while (que.size()){
        auto tp = que.front();
        que.pop();
        vis[tp] = false;

        for(auto &e : eg[tp]){
            if(dist[tp] + e.second < dist[e.first]){
                dist[e.first] = dist[tp] + e.second;
                if(!vis[e.first]) que.push(e.first);
                vis[e.first] = true;
            }
        }
    }

    if(dist[n] == INF) printf("impossible");
    else printf("%d", dist[n]);
}