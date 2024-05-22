#include <stdio.h>

#define MAX 10

int n;

int chessboard[MAX][MAX];

int check(int x, int y){
    for(int i = 0; i < n; i++){
        if(chessboard[x][i] || chessboard[i][y])
            return 0;
    }
    for(int i = 1; x + i < n && y + i < n; i++)
        if(chessboard[x + i][y + i])
            return 0;
    for(int i = 1; x - i > -1 && y - i > -1; i++)
        if(chessboard[x - i][y - i])
            return 0;
    for(int i = 1; x - i > -1 && y + i < n; i++)
        if(chessboard[x - i][y + i])
            return 0;
    for(int i = 1; x + i < n && y - i > -1; i++)
        if(chessboard[x + i][y - i])
            return 0;
    return 1;
}

void eureka(int ind){
    if(ind > n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                printf("%c", chessboard[i][j] ? 'Q' : '.');
            printf("\n");
        }
        printf("\n");
        return;
    }

    for(int i = 0; i < n; i++)
        if(check(i, ind - 1)){
            chessboard[i][ind - 1] = 1;
            eureka(ind + 1);
            chessboard[i][ind - 1] = 0;
        }
}

int main(){
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < n; j++)
            chessboard[i][j] = 0;
    eureka(1);
}