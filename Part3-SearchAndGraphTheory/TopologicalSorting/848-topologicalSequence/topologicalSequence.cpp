#include <cstdio>
#include <vector>
#include <queue>

#define MAX 100010

using namespace std;

vector<int> eg[MAX];
queue<int> que;

int path[MAX];
int in[MAX];
bool out[MAX];
int len = 0;

int n, m;

int main(){
    scanf("%d %d", &n, &m);

    int from, to;
    while(m--){
        scanf("%d %d", &from, &to);
        eg[from].push_back(to);
        in[to]++;
    }

    while(true){
        for(int i = 1; i <= n; i++){
            if(!in[i] && !out[i]) que.push(i);
        }
        if(que.empty()) break;
        else while(!que.empty()){
            int nd = que.front();
            que.pop();
            for(auto e : eg[nd]) in[e]--;
            path[len++] = nd;
            out[nd] = true;
        }
    }

    if(len == n) for(int i = 0; i < len; i++) printf("%d ", path[i]);
    else printf("-1");

}
