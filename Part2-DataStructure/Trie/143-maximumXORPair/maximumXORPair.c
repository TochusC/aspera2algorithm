#include <stdio.h>

#define MAX 2000010
#define MAX_BIT 40

typedef long long ll;

struct Node{
    int ptr[2];
};

struct Node nodes[MAX];
ll nodeNum = 1;

void insert(ll val){
    int bits[MAX_BIT];
    for(int i = 0; i < MAX_BIT; i++){
        bits[i] = val % 2;
        val /= 2;
    }

    int traveler = 0;
    for(int i = MAX_BIT - 1; i >= 0; i--){
        int bit = bits[i];
        if(nodes[traveler].ptr[bit] == 0){
            nodes[nodeNum].ptr[0] = 0;
            nodes[nodeNum].ptr[1] = 0;
            nodes[traveler].ptr[bit] = nodeNum;
            traveler = nodeNum++;
        }
        else traveler = nodes[traveler].ptr[bit];
    }
}

ll find(ll val) {
    int traveler = 0;
    ll rst = 0;

    int bits[MAX_BIT];
    for(int i = 0; i< MAX_BIT; i++, val/=2)
        bits[i] = val % 2;

    long long base = 1;

    for(int i = 1; i < MAX_BIT; i++){
        base *= 2;
    }

    for(int i = MAX_BIT - 1; i >= 0; i--){
        int bit = bits[i];
        if (nodes[traveler].ptr[!bit] != 0) {
            rst += base;
            traveler = nodes[traveler].ptr[!bit];
        }else if (nodes[traveler].ptr[bit] != 0){
            traveler = nodes[traveler].ptr[bit];
        }
        else{
            break;
        }
        base /= 2;
    }
    return rst;
}

ll arr[MAX];

ll max(ll a, ll b){
    if(a > b)
        return a;
    else
        return b;
}

int main(){
    nodes[0].ptr[0] = 0;
    nodes[0].ptr[1] = 0;

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
        insert(arr[i]);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, find(arr[i]));
    }
    printf("%lld", ans);
}