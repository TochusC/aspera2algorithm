#include <stdio.h>

#define MAX 1000100

int n, m;
char p[MAX], s[MAX];

int next[MAX];
void kmpInit(char *m){
    next[0] = -1;
    if(m[1] != '\0'){
        next[1] = 0;
        int i, prev;
        for(i = 2; m[i] != '\0'; i++){
            prev = next[i-1];
            if(m[i - 1] == m[prev]) next[i] = prev + 1;
            else{
                int rst = 0;
                for(int t = prev; t > 0; t--){
                    int j;
                    for(j = 0; j < prev; j++){
                        if(m[j] != m[i - t + j]) break;
                    }
                    if(j==prev) rst = j;
                }
                next[i] = rst;
            }
        }
        prev = next[i-1];
        if(m[i - 1] == m[prev]) next[i] = prev + 1;
        else{
            int rst = -1;
            for(int t = prev; t > 0; t--){
                int j;
                for(j = 0; j < prev; j++){
                    if(m[j] != m[i - t + j]) break;
                }
                if(j==prev) rst = j;
            }
            next[i] = rst;
        }
    }
    for(int i = 1; m[i] != '\0'; i++)
        if(m[next[i]] == m[i]) next[i] = next[next[i]];
}

void kmpSearch(char *n, char *m){
    int i, j = 0;
    for(i = 0; n[i] != '\0'; i++, j++){
        if(m[j] == '\0'){
            printf("%d ", i - j);
            j = next[j];
        }
        if(n[i] != m[j]) {
            j = next[j];
        }
    }
    if(m[j] == '\0'){
        printf("%d ", i - j);
    }
}

int main(){
    scanf("%d", &n);
    scanf("%s", p);

    scanf("%d", &m);
    scanf("%s", s);

    kmpInit(p);
    kmpSearch(s, p);
}