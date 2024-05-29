#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <utility>

#define MAX 1010

using namespace std;

void toLower(string &str){
    for(auto &c : str)
        if(c >= 'A' && c <= 'Z')
            c += 'a' - 'A';
}
set<string> artA, artB;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    string wrd;
    while(n--){
        cin >> wrd;
        toLower(wrd);
        if(!artA.count(wrd))
            artA.insert(wrd);
    }
    while(m--){
        cin >> wrd;
        toLower(wrd);
        if(!artB.count(wrd))
            artB.insert(wrd);
    }

    int uni = 0;
    int dif = 0;
    for(auto & e : artA){
        if(artB.count(e)) uni++;
        else dif++;
    }

    printf("%d\n", uni);
    printf("%d", int(artB.size()) + dif);
}
