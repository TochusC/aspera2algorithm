#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

#define MAX 100010

using namespace std;

vector<int>eg[MAX];
queue<pair<int, int>> que;

bool vis[MAX];

int n, m;

int main(){
    scanf("%d %d", &n ,&m);

    int from, to;
    while(m--){
        scanf("%d %d", &from, &to);
        eg[from].push_back(to);
    }
    que.push({1, 0});

    while(!que.empty()){
        auto now = que.front();
        que.pop();

        if(vis[now.first]) continue;
        else vis[now.first] = true;

        if(now.first == n){
            printf("%d\n", now.second);
            return 0;
        }
        for(auto e : eg[now.first])
            que.push({e, now.second + 1});
    }
    printf("-1\n");
}
