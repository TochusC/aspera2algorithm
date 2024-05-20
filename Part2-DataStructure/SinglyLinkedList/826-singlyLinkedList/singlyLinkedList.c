#include <stdio.h>

#define MAX 100010

struct LinkNode{
    int val;
    int next;
};


struct List{
    struct LinkNode nodes[MAX];
    int len;
    int head;
};

struct LinkNode list[MAX];
int len = 0;
int cur;

int main(){
    struct List list;
    list.len = 0;
    list.head = -1;
    list.nodes[0].val = -1;
    list.nodes[0].next = -1;

    int n;
    scanf("%d", &n);

    char op;
    int p1, p2;
    while(n--){
        getchar();
        scanf("%c", &op);
        if(op == 'H'){
            scanf(" %d", &p1);
            list.nodes[list.len].val = p1;
            list.nodes[list.len].next = list.head;
            list.head = list.len++;
        }
        else if(op == 'D'){
            scanf(" %d", &p1);
            if(p1 == 0){
                list.head = list.nodes[list.head].next;
            }
            else{
                p1-=1;
                list.nodes[p1].next = list.nodes[list.nodes[p1].next].next;
            }
        }
        else if(op == 'I'){
            scanf(" %d %d", &p1, &p2);
            p1-=1;
            list.nodes[list.len].val = p2;
            list.nodes[list.len].next = list.nodes[p1].next;
            list.nodes[p1].next = list.len++;
        }
    }

    int traveler = list.head;
    while(traveler != -1){
        printf("%d ", list.nodes[traveler].val);
        traveler = list.nodes[traveler].next;
    }
}