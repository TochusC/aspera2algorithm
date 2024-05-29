#include <cstdio>
#include <utility>
#include <queue>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Droplet{
    int pos, num;

    Droplet(int pos, int num):pos(pos), num(num){}

    bool operator<(const Droplet & ano) const{
        return this->pos < ano.pos;
    }
    bool operator<(const int & pos) const{
        return this->pos < pos;
    }
};
list<Droplet> dropList;
stack<list<Droplet>::iterator> bombQue;

void bomb(){
    while(!bombQue.empty()){
        auto drop = bombQue.top();
        bombQue.pop();

        auto left = dropList.end();
        auto right = ++drop;
        drop--;

        if(drop != dropList.begin()) {
            left = --drop;
            drop++;
        }

//        printf("ERASED! %d\n", drop->pos);
        dropList.erase(drop);
//        printf("Left: %d, right: %d\n", left->pos, right->pos);

        if(right != dropList.end())
            if(++right->num == 5) bombQue.push(right);
        if(left != dropList.end())
            if(++(left->num) == 5) bombQue.push(left);
    }
}

int main(){
    int c, m, n;
    scanf("%d %d %d", &c, &m, &n);

    int pos, num;
    while(m--){
        scanf("%d %d", &pos, &num);
        auto it = lower_bound(dropList.begin(), dropList.end(), pos);
        dropList.insert(it, Droplet(pos, num));
    }
    while(n--){
        scanf("%d", &pos);
        auto it = lower_bound(dropList.begin(), dropList.end(), pos);
        if(it == dropList.end() || it->pos != pos)
            dropList.insert(it, {pos, 1});
        else if(it->pos == pos) {
            if(++it->num ==5){
                bombQue.push(it);
                bomb();
            }
        }
        printf("%d\n", dropList.size());
//        for(auto &e:dropList)
//            printf("%d %d\n", e.pos, e.num);
//        printf("\n");
    }
}
