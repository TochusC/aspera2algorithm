#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

#define MAX 100010

vector<pair<int, int>>eg[MAX];
bool vis[MAX];

int num = 0;


int dfs(int pos){
    vis[pos] = true;
    int rst = 1;

    for(auto &e : eg[pos]){
        if(vis[e.first]) continue;
        e.second = dfs(e.first);
        rst += e.second;
    }

    return rst;
}

int ans = 1e6;

int eureka(int pos, int pre){
    int rst = 0, con = 0;
    vis[pos] = true;

    for(auto &e : eg[pos]){
        if(vis[e.first]) e.second = pre + 1;
        con += e.second;
        rst = max(rst, e.second);
    }

    for(auto &e : eg[pos])
        if(!vis[e.first]) rst = min(rst, eureka(e.first, con - e.second));

    return rst;
}

int main(){
    scanf("%d", &num);
    int from, to;
    for(int i = 0; i < num; i++){
        scanf("%d %d", &from, &to);
        eg[from].push_back({to, -1});
        eg[to].push_back({from, -1});
    }

    dfs(1);
    for(int i = 0; i < MAX; i++)
        vis[i] = false;

    printf("%d\n", eureka(1, -1));
}