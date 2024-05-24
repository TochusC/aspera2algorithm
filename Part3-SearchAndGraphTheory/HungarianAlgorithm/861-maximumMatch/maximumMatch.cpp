#include <cstdio>
#include <vector>
#include <utility>

#define NMAX 550

using namespace std;

vector<int> eg[NMAX];
bool sel[NMAX];

int match[NMAX];

bool eureka(int nd){
    for(auto &e : eg[nd]){
        if(sel[e]) continue;
        sel[e] = true;
        if(!match[e] || eureka(match[e])) {
            match[e] = nd;
            return true;
        }
    }
    return false;
}

int main(){
    int n1, n2, m;
    scanf("%d %d %d", &n1, &n2, &m);

    int from, to;
    while(m--){
        scanf("%d %d", &from, &to);
        eg[from].push_back(to);
    }

    int res = 0;
    for(int i = 1; i <= n1; i++){
        for(auto &e:sel) e = false;
        if(eureka(i)) res++;
    }

    printf("%d\n", res);
}
