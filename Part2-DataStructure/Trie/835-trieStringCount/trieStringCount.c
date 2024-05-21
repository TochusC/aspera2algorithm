#include <stdio.h>

#define MAX 100010
#define NUM 30

struct Node{
    char chr;
    int ptr[NUM];
    int cnt;
};

struct Node nodes[MAX];
int nodeNum = 1;

void insert(char *str){
    int traveler = 0;
    for(int i = 0; str[i] != '\0'; i++){
        char chr = str[i];
        if (nodes[traveler].ptr[chr - 'a'] == 0){
            nodes[nodeNum].chr = chr;
            for(int j = 0; j < NUM; j++)
                nodes[nodeNum].ptr[j] = 0;
            nodes[nodeNum].cnt = 0;

            nodes[traveler].ptr[chr - 'a'] = nodeNum;
            traveler = nodeNum++;
        }
        else traveler = nodes[traveler].ptr[chr - 'a'];
    }
    nodes[traveler].cnt++;
}

int query(char *str){
    int traveler = 0;
    for(int i = 0; str[i] != '\0'; i++){
        char chr = str[i];
        if (nodes[traveler].ptr[chr - 'a'] == 0){
            return 0;
        }
        else traveler = nodes[traveler].ptr[chr - 'a'];
    }
    return nodes[traveler].cnt;
}

int main(){
    nodes[0].chr = '-';
    for(int i = 0; i < NUM; i++)
        nodes[0].ptr[i] = 0;
    nodes[0].cnt = 0;

    int n;
    scanf("%d", &n);

    char op[5];
    char str[MAX];
    while(n--){
        scanf("%s", &op);
        scanf("%s", str);

        if(op[0] == 'I')
            insert(str);
        else if (op[0] == 'Q')
            printf("%d\n", query(str));
    }
}