#include <cstdio>
#include <queue>

using namespace std;

#define MAX 101

int maz[MAX][MAX];
bool vis[MAX][MAX];

struct stas{
    int x, y, step;
};
queue<stas> que;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int x = 0; x < n; x++)
        for(int y = 0; y < m; y++)
            scanf("%d", &maz[x][y]);

    que.push({0, 0, 0});
    while(!que.empty()){
        stas now = que.front();
        que.pop();
        if(now.x < 0 || now.x >= n || now.y < 0 || now.y >= m || vis[now.x][now.y] || maz[now.x][now.y]) continue;
        vis[now.x][now.y] = true;

        if(now.x == n - 1 && now.y == m - 1){
            printf("%d\n", now.step);
            return 0;
        }
        for(auto &inc : {-1, 1}){
            que.push({now.x + inc, now.y, now.step + 1});
            que.push({now.x, now.y + inc, now.step + 1});
        }
    }
}