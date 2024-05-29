#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
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
    bool operator>(const Droplet & ano) const{
        return this->pos < ano.pos;
    }
};
vector<Droplet> dropVec;

queue<int> bombQue;
void checkBomb(vector<Droplet>::iterator pos){
    if(pos->num >= 5){
        int loc = pos->pos;
        dropVec.erase(pos);

        auto left = dropVec.end();
        auto right = dropVec.end();

        auto it = lower_bound(dropVec.begin(), dropVec.end(), loc);

        if(it != dropVec.begin()){
            left = it - 1;
            left->num++;
        }
        if(it != dropVec.end()){
            right = it;
            right->num++;
        }

        if(left != dropVec.end())
            checkBomb(left);
        if(right != dropVec.end())
            checkBomb(right);
    }
}

int main(){
    int c, m, n;
    scanf("%d %d %d", &c, &m, &n);

    int pos, num;
    while(m--){
        scanf("%d %d", &pos, &num);
        dropVec.emplace_back(pos, num);
    }
    sort(dropVec.begin(), dropVec.end());
    while(n--){
        scanf("%d", &pos);
        auto it = lower_bound(dropVec.begin(), dropVec.end(), pos);
        if(it == dropVec.end() || it->pos != pos)
            dropVec.insert(it, {pos, 1});
        else if(it->pos == pos) {
            it->num++;
            checkBomb(it);
        }
        printf("%d\n", dropVec.size());
//        for(auto &e:dropVec)
//            printf("%d %d\n", e.pos, e.num);
//        printf("\n");
    }
}