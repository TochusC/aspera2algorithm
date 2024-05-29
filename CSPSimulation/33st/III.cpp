#include <cstdio>
#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <set>
#include <map>

#define COMMAX 50
#define ELMMAX 50
#define ATOMAX 50
#define EPS 1e-6

#define MAX 50

using namespace std;

struct ELM{
    string name;
    int index;
};

int globalIndex = 0;
map<string, ELM *> elmMap;

typedef pair<ELM *, int> ElmPtr;

struct COMP{
    vector<ElmPtr> elmPtrList;
};

ElmPtr getElmPtr(string &nme, int num){
    auto elm = elmMap.find(nme);
    if(elm == elmMap.end()){
        auto newElm = new ELM();
        newElm->name = nme;
        newElm->index = globalIndex++;
        elmMap.emplace(nme, newElm);
        return make_pair(newElm, num);
    }
    else return make_pair(elm->second, num);
}

COMP* str2comp(string str){
    auto newComp = new COMP();

    int prevChar = -1;  // -1 初始 0 字符 1 数字
    int num = 0;
    string nme;
    for(auto &chr : str){
        if(isdigit(chr)){
            if(prevChar == 1) num = num * 10 + chr - '0';
            else num = chr - '0';
            prevChar = 1;
        }
        else{
            if(prevChar == 1) {
                newComp->elmPtrList.push_back(getElmPtr(nme, num));
                nme.clear(); num = 0;
            }
            nme.push_back(chr);
            prevChar = 0;
        }
    }
    if(num > 0) newComp->elmPtrList.push_back(getElmPtr(nme, num));
    return newComp;
}

double mat[MAX][MAX];

bool isZero(double val){
    return abs(val) < EPS;
}


void swapLine(int li1, int li2){
    for(int i = 0; i < globalIndex; i++){
        double tmp = mat[li1][i];
        mat[li1][i] = mat[li2][i];
        mat[li2][i] = tmp;
    }
}

void minusLine(int x1, int y1,  int len){
    for(int i = y1 + 1; i < len; i++){
        double fac = mat[i][x1] / mat[y1][x1];
        for(int j = x1; j < globalIndex; j++)
            mat[i][j] -= fac * mat[y1][j];
    }
}

void printMat(int len){
//    for(int i = 0; i < len; i++){
//        for(int j = 0; j < globalIndex; j++)
//            printf("%lf ", mat[i][j]);
//        printf("\n");
//    }
//    printf("\n");
}

void refresh(){
    globalIndex = 0;
    for(auto &e : elmMap)
        delete(e.second);
    elmMap.clear();
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            mat[i][j] = 0;
}

bool eureka(int x1, int y1, int len){
    int del;
    for(del = x1; del < globalIndex; del++){
        for(int i = y1; i < len; i++){
            if(mat[i][del] != 0) goto fin;
        }
    }
    fin:
    if(mat[y1][del] == 0){
        for(int lin = y1 + 1; lin < len; lin++)
            if(mat[lin][del] != 0) {
                swapLine(y1, lin);
                break;
            }
    }
    minusLine(del, y1, len);
    printMat(len);
    if(x1 + 1 < globalIndex && y1 +1 < len)
        eureka(x1+1, y1+1, len);

    int zhi = 0;
    if(!x1&&!y1){
        for(int i = 0; i < len; i++)
            for(int j = 0; j < globalIndex; j++){
                if(mat[i][j] != 0){
                    zhi++;
                    break;
                }
            }
        if(zhi < globalIndex) return true;
        else return false;
    }
    return false;
}


int main(){
    int n;
    scanf("%d", &n);

    int len;
    string compStr;
    while(n--){
        refresh();
        scanf("%d", &len);
        for(int i = 0; i < len; i++){
            cin >> compStr;
            auto comp = str2comp(compStr);
            for(auto &e : comp->elmPtrList){
                mat[e.first->index][i] = e.second;
            }
            delete comp;
        }

        int tmp = len;
        len = globalIndex;
        globalIndex = tmp;

        printMat(len);

        if(eureka(0, 0, len)) printf("Y\n");
        else printf("N\n");
    }
}