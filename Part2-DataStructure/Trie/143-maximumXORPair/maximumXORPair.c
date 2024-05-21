#include <stdio.h>

#define MAX 100000
#define MAX_BIT 32

struct Node{
    int exi;
    int ptr[2];
};

struct Node nodes[MAX];
int nodeNum = 1;

void insert(int val){
    int traveler = 0;
    while(val){
        int bit = val % 2;
        if(!nodes[traveler].ptr[bit]){
            nodes[nodeNum].exi = 1;
            nodes[nodeNum].ptr[0] = 0;
            nodes[nodeNum].ptr[1] = 0;
            nodes[traveler].ptr[bit] = nodeNum;
            traveler = nodeNum++;
        }
        else traveler = nodes[traveler].ptr[bit];
        val /= 2;
    }
}

int main(){
    nodes[0].exi = 1;
    nodes[0].ptr[0] = 0;
    nodes[0].ptr[1] = 0;

    int n;
    scanf("%d", &n);

    int val;
    while(n--){
        scanf("%d", &val);
    }
}