#include <stdio.h>

#define MAX 1010

typedef long long ll;

int mat[MAX][MAX];
ll sumMat[MAX][MAX];


int main(){
    int sizeX, sizeY, queryNum;
    scanf("%d %d %d", &sizeX, &sizeY, &queryNum);

    int val;
    for(int row = 0; row < sizeX; row++){
        for(int column = 0; column < sizeY; column++){
            scanf("%d", &val);
            mat[row][column] = val;
            sumMat[row + 1][column + 1] = val + sumMat[row + 1][column]
                    + sumMat[row][column + 1] - sumMat[row][column];
        }
    }

    int rowMin, columnMin, rowMax, columnMax;
    while(queryNum--){
        scanf("%d %d %d %d", &rowMin, &columnMin,
              &rowMax, &columnMax);

        printf("%lld\n", sumMat[rowMax][columnMax] + sumMat[rowMin - 1][columnMin - 1]
        - sumMat[rowMax][columnMin - 1] - sumMat[rowMin - 1][columnMax]);
    }
}