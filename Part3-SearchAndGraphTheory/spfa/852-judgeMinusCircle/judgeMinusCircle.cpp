#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

#define NMAX 2010
#define MMAX 10010
#define INF 1e8

using namespace std;

typedef pair<int, int> PII;

vector<PII> eg[NMAX];
queue<int> que, que2;
int dist[NMAX];
bool vis[NMAX];
int tim[NMAX];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int from, to, wig;
    while(m--){
        scanf("%d %d %d", &from, &to, &wig);
        eg[from].emplace_back(to, wig);
    }

    for(auto &dis : dist) dis = INF;

    for(int i = 1; i<= n; i++){
        que.push(i);
        vis[i] = true;
        dist[i] = 0;
        tim[i]++;
    }
    while (que.size()){
        auto tp = que.front();
        que.pop();
        vis[tp] = false;

        for(auto &e : eg[tp]){
            if(dist[tp] + e.second < dist[e.first]){
                dist[e.first] = dist[tp] + e.second;
                if(!vis[e.first]){
                    que.push(e.first);
                    tim[e.first]++;
                    if(tim[e.first] == n + 1){
                        printf("Yes");
                        return 0;
                    }
                }
                vis[e.first] = true;
            }
        }
    }

    printf("No");
};