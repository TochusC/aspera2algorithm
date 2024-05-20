#include <stdio.h>

#define MAX 1010

typedef long long ll;

int mat[MAX][MAX];
ll difMat[MAX][MAX];

int main(){
    int rows, columns, queryNum;

    scanf("%d %d %d", &rows, &columns, &queryNum);

    int val;
    for(int row = 1; row <= rows; row++){
        for(int column = 1; column <= columns; column++){
            scanf("%d", &val);
            mat[row][column] = val;
            difMat[row][column] = val + mat[row - 1][column - 1]
                    - mat[row][column - 1] - mat[row - 1][column];
        }
    }

    int x1, y1, x2, y2, c;
    while(queryNum--){
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        difMat[x1][y1] += c;
        difMat[x2 + 1][y2 + 1] += c;
        difMat[x1][y2 + 1] -= c;
        difMat[x2 + 1][y1] -= c;
    }

    for(int row = 1; row <= rows; row++){
        for(int column = 1; column <= columns; column++){
            mat[row][column] = mat[row - 1][column] + mat[row][column - 1]
                    - mat[row - 1][column - 1] + difMat[row][column];
            printf("%d ", mat[row][column]);
        }
        printf("\n");
    }
}