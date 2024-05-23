#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

#define MAX 160010
#define INF 1e9

using namespace std;

typedef pair<int, int> PII;

int dist[MAX];
bool vis[MAX];
vector<PII> eg[MAX];
priority_queue<PII, vector<PII>, greater<PII>> heap;


int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int from, to, wig;
    while(m--){
        scanf("%d %d %d", &from, &to, &wig);
        eg[from].emplace_back(to, wig);
    }

    for(auto &e:dist) e = INF;

    heap.emplace(0, 1);
    dist[1] = 0;

    while(heap.size()){
        auto tp = heap.top();
        heap.pop();

        if(vis[tp.second]) continue;
        else vis[tp.second] = true;

        for(auto e : eg[tp.second]){
            if(dist[e.first] > e.second + tp.first){
                dist[e.first] = e.second + tp.first;
                heap.emplace(dist[e.first], e.first);
            }
            dist[e.first] = min(e.second + tp.first, dist[e.first]);
        }
    }

    printf("%d", dist[n] == INF ? -1 : dist[n]);
}