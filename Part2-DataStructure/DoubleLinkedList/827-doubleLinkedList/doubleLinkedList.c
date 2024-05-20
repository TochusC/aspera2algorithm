#include <stdio.h>

#define MAX 100010

struct LinkNode{
    int val;
    int next;
    int prev;
};


struct List{
    struct LinkNode nodes[MAX];
    int len;
    int head;
};

struct LinkNode list[MAX];

int main(){
    struct List list;
    list.len = 1;
    list.head = 0;

    list.nodes[0].val = -1;
    list.nodes[0].next = 0;
    list.nodes[0].prev = 0;

    int n;
    scanf("%d", &n);

    char op, postfix;
    int p1, p2;
    while(n--){
        getchar();
        scanf("%c", &op);
        if(op == 'L'){
            scanf(" %d", &p1);
            list.nodes[list.len].val = p1;
            list.nodes[list.len].next = list.nodes[list.head].next;
            list.nodes[list.len].prev = list.head;

            list.nodes[list.nodes[list.len].next].prev = list.len;
            list.nodes[list.head].next = list.len++;
        }
        else if(op == 'R'){
            scanf(" %d", &p1);
            list.nodes[list.len].val = p1;
            list.nodes[list.len].next = list.head;
            list.nodes[list.len].prev = list.nodes[list.head].prev;
            list.nodes[list.nodes[list.head].prev].next = list.len;
            list.nodes[list.head].prev = list.len++;
        }
        else if(op == 'D'){
            scanf(" %d", &p1);
            int prev = list.nodes[p1].prev;
            int next = list.nodes[p1].next;
            list.nodes[prev].next = next;
            list.nodes[next].prev = prev;
        }
        else if(op == 'I'){
            scanf("%c", &postfix);
            scanf(" %d %d", &p1, &p2);
            list.nodes[list.len].val = p2;
            if(postfix == 'L'){
                list.nodes[list.len].next = p1;
                list.nodes[list.len].prev = list.nodes[p1].prev;
                list.nodes[list.nodes[p1].prev].next = list.len;
                list.nodes[p1].prev = list.len;
            }
            else{
                list.nodes[list.len].prev = p1;
                list.nodes[list.len].next = list.nodes[p1].next;
                list.nodes[list.nodes[p1].next].prev = list.len;
                list.nodes[p1].next = list.len;
            }
            list.len++;
        }
    }

    int traveler = list.nodes[list.head].next;
    while(traveler != 0){
        printf("%d ", list.nodes[traveler].val);
        traveler = list.nodes[traveler].next;
    }
}