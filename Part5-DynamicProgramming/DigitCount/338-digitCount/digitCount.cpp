#include <cstdio>
#include <string>

#define MAX 1e8 + 10
#define MAXBIT 10

using namespace std;

int tm[MAXBIT];
int ans[MAXBIT];
int all = 0;

int main(){
    tm[2] = 1;
    for(int i = 3; i < MAXBIT; i++){
        tm[i] = tm[i - 1] * 10;
    }

    int a, b;
    while(true){
        scanf("%d %d", &a, &b);
        if(!a&&!b) return 0;

        all = 0;
        for(auto &e : ans) e = 0;

        if(a > b){
            int tmp = a;
            a = b;
            b = tmp;
        }
        int pos = 0;
        int nextRO = 0;
        while(b){
            pos++;
            int ditB = b % 10;
            int ditA = a % 10;
            b /= 10; a/= 10;
            int realOff = 0;
            int off = ditB - ditA;
            if(off < 0){
                for(int p = ditB; p >= 0; p--, realOff++) ans[p]++;
                for(int p = ditA; p < MAXBIT; p++, realOff++) ans[p]++;
                a++;
            }
            else for(int p = ditA; p <= ditB; p++, realOff++) ans[p]++;
            all += (realOff - 1) * tm[pos];
        }
        for(auto &e : ans) printf("%d ", e + all);
        printf("\n");
    }
}