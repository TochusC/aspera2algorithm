#include <cstdio>

#define MAX 110

bool vis[110];
int cnt[110];
int cpt[110];

int main(){
    int m, n;
    scanf("%d %d", &n, &m);

    int len = 0;
    int wrd;
    while(n--){
        for(auto &e : vis) e = false;

        scanf("%d", &len);

        while(len--){
            scanf("%d", &wrd);
            cnt[wrd]++;
            if(!vis[wrd]){
                vis[wrd] = true;
                cpt[wrd]++;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        printf("%d %d\n", cpt[i], cnt[i]);
    }
}