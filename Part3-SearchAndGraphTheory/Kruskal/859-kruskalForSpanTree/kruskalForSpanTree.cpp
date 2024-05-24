#include <cstdio>
#include <queue>
#include <set>

#define NMAX 100010

using namespace std;

struct Edge{
    int wig, from, to;
    Edge(int wig, int from, int to):wig(wig), from(from), to(to){}
    bool operator<(const Edge &oth) const {
        return this->wig < oth.wig;
    }
    bool operator>(const Edge &oth) const{
        return this->wig > oth.wig;
    }
};

priority_queue<Edge, vector<Edge>, greater<Edge>> que;

struct UniSet{
    int root[NMAX];

    UniSet(){
        for(int i = 0; i < NMAX; i++)
            root[i] = -1;
    }
    bool same(int a, int b){
        return findPar(a) == findPar(b);
    }
    void merge(int a, int b){
        a = findPar(a);
        b = findPar(b);
        if(a == b) return;
        root[a] += root[b];
        root[b] = a;
    }

    int findPar(int elm){
        int tra = elm;
        while(root[tra] > 0) tra = root[tra];
        while(tra != elm){
            int next = root[elm];
            root[elm] = tra;
            elm = next;
        }
        return tra;
    }
};

UniSet uniSet = UniSet();

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int from, to, wig;
    while(m--){
        scanf("%d %d %d", &from, &to, &wig);
        que.emplace(wig, from, to);
    }

    int mergeNum = 0;
    int ans = 0;
    while(!que.empty() && mergeNum < n - 1){
        Edge edge = que.top();
        que.pop();

        if(uniSet.same(edge.from, edge.to)) continue;

        ans += edge.wig;
        uniSet.merge(edge.from, edge.to);
        mergeNum ++;
    }
    if(mergeNum == n - 1) printf("%d", ans);
    else printf("impossible");
}