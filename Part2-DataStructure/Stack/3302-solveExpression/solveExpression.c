#include <stdio.h>

#define MAX 100010

char ops[MAX];
int nums[MAX];

int opsLvl[256];

int main(){
    opsLvl['+'] = 1;
    opsLvl['-'] = 2;
    opsLvl['*'] = 3;
    opsLvl['/'] = 3;
    opsLvl['s'] = -1;

    int opsNum = 0;
    int numNum = 0;
    ops[opsNum++] = 's';

    char chr;
    int num = -1;
    while((chr = getchar()) != -1){
        if(chr >= '0' && chr <= '9'){
            if(num == -1) num = 0;
            num = num * 10 + chr - '0';
        }
        else{
            if(num >= 0){
                nums[numNum++] = num;
                num = -1;
            }
            if(chr == ')'){
                char op = ops[--opsNum];
                while(op != '('){
                    int rVal = nums[--numNum];
                    int lVal = nums[--numNum];
                    if(op == '+') nums[numNum++] = lVal + rVal;
                    else if(op == '-') nums[numNum++] = lVal - rVal;
                    else if(op == '*') nums[numNum++] = lVal * rVal;
                    else if(op == '/') nums[numNum++] = lVal / rVal;
                    op = ops[--opsNum];
                }
            }
            else if(chr == '('){
                ops[opsNum++] = chr;
            }
            else if(opsLvl[chr] <= opsLvl[ops[opsNum - 1]]){
                while(opsLvl[chr] <= opsLvl[ops[opsNum - 1]]){
                    char op = ops[--opsNum];
                    int rVal = nums[--numNum];
                    int lVal = nums[--numNum];
                    if(op == '+') nums[numNum++] = lVal + rVal;
                    else if(op == '-') nums[numNum++] = lVal - rVal;
                    else if(op == '*') nums[numNum++] = lVal * rVal;
                    else if(op == '/') nums[numNum++] = lVal / rVal;
                }
                ops[opsNum++] = chr;
            }
            else{
                ops[opsNum++] = chr;
            }
        }
    }
    if(num != -1){
        nums[numNum++] = num;
        num = -1;
    }

    while(opsNum > 1){
        char op = ops[--opsNum];

        int rVal = nums[--numNum];
        int lVal = nums[--numNum];

        if(op == '+') nums[numNum++] = lVal + rVal;
        else if(op == '-') nums[numNum++] = lVal - rVal;
        else if(op == '*') nums[numNum++] = lVal * rVal;
        else if(op == '/') nums[numNum++] = lVal / rVal;
    }

    printf("%d", nums[--numNum]);
}