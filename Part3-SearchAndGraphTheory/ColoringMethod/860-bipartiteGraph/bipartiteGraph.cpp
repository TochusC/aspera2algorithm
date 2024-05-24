#include <cstdio>
#include <vector>
#include <utility>

#define NMAX 100010
#define MMAX 100010

using namespace std;

typedef pair<int, int> PII;

vector<int>eg[NMAX];
int ndc[NMAX];
bool vis[NMAX];

bool eureka(int nd, int col){
    if(vis[nd]){
        if(ndc[nd] != col) return false;
        else return true;
    }
    ndc[nd] = col;
    vis[nd] = true;
    for(auto &e : eg[nd]){
        if(!eureka(e, !col)) return false;
    }
    return true;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int from, to;
    while(m--){
        scanf("%d %d", &from, &to);
        eg[from].push_back(to);
        eg[to].push_back(from);
    }


    bool con = true;
    while(con){
        con = false;
        for(int i = 1; i <= n; i++){
            if(vis[i]) continue;
            else con = true;
            if(eureka(i, 1)) continue;
            printf("No");
            return 0;
        }
    }
    printf("Yes");
}