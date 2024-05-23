#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <utility>

#define MAX 9

using namespace std;

set<string> st;
queue<pair<string, int>> que;


int eureka(string ini){
    que.push({ini, 0});

    while(que.size()){
        pair<string, int> now = que.front();
        que.pop();

        if(st.count(now.first)) continue;
        st.insert(now.first);

        int pos = now.first.find('x');
        if(pos == MAX-1) if(now.first == "12345678x") return now.second;

        for(auto &ind : {-3, 3})
            if(pos + ind > -1 && pos + ind < MAX){
                string next = now.first;
                swap(next[pos], next[pos + ind]);
                que.push({next, now.second + 1});
            }
        if(pos % 3 != 0){
            string next = now.first;
            swap(next[pos], next[pos - 1]);
            que.push({next, now.second + 1});
        }
        if(pos % 3 != 2){
            string next = now.first;
            swap(next[pos], next[pos + 1]);
            que.push({next, now.second + 1});
        }
    }
    return -1;
}

int main(){
    char str[MAX], chr;
    for(int i = 0; i < MAX; i++){
        scanf(" %c", &chr);
        str[i] = chr;
    }
    printf("%d\n", eureka(string(str)));
}