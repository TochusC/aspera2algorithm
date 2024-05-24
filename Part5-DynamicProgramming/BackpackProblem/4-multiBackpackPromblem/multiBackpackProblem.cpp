#include <cstdio>
#include <utility>
#include <algorithm>

#define NMAX 2010
#define VMAX 2010
#define MAX 101000

using namespace std;

struct Item{
    int vol, val;
};

int dp[NMAX];
Item item[MAX];
int sz = 0;

int main(){
    int n, v;
    scanf("%d %d", &n, &v);

    int vol, val, num;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &vol, &val, &num);
        for(int k = 1; k <= num; k *= 2){
            item[sz].vol = vol * k;
            item[sz].val = val * k;
            num -= k;
            sz++;
        }
        if(!num) continue;
        item[sz].vol = vol * num;
        item[sz].val = val * num;
        sz++;
    }

    for(int t = 0; t < sz; t++)
        for(int j = v; j >= item[t].vol; j--)
            dp[j] = max(dp[j], dp[j - item[t].vol] + item[t].val);

    printf("%d", dp[v]);
}