#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define NMAX 510
#define KMAX 510
#define MMAX 10010
#define INF 1e8

using namespace std;

struct Edge{
    int from, to, wig;
};

Edge eg[MMAX];

int dis[NMAX];
int bac[NMAX];

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m ,&k);

    int from, to, wig;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &from, &to, &wig);
        eg[i].from = from;
        eg[i].to = to;
        eg[i].wig = wig;
    }

    for(auto &e : dis)
        e = INF;
    dis[1] = 0;

    for(int i = 0; i < k; i++){
        for(int j = 1; j <= n; j++) bac[j] = dis[j];
        for(int j = 0; j < m; j++){
            if(bac[eg[j].from] == INF) continue;
            dis[eg[j].to] = min(bac[eg[j].from] + eg[j].wig, dis[eg[j].to]);
        }
    }

    if(dis[n] == INF) printf("impossible");
    else printf("%d", dis[n]);
}