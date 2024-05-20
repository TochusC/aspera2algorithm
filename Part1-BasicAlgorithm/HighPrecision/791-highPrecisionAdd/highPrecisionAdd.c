#include <stdio.h>
#include <stdbool.h>

#define MAX_BIT 100010


typedef struct {
    char bits[MAX_BIT];
    int length;
} Num;

void addNum(Num *a, Num *b){
    int carry = 0, index = 0;

    for(index = 0; index < a->length && index < b->length; index++){
        a->bits[index] = a->bits[index] + b->bits[index] + carry;
        carry = a->bits[index] / 10;
        a->bits[index] %= 10;
    }
    while(index < b->length){
        a->bits[index] = b->bits[index] + carry;
        carry = a->bits[index] / 10;
        a->bits[index] %= 10;
        a->length++;
        index++;
    }
    while(carry){
        if(index < a->length){
            a->bits[index] = a->bits[index] + carry;
            carry = a->bits[index] / 10;
            a->bits[index] %= 10;
            index++;
        }
        else{
            a->bits[index++] = carry;
            a->length++;
            carry = 0;
        }
    }
}

void printNum(Num *num){
    for(int pos = num->length - 1; pos >= 0; pos--){
        printf("%c", '0' + num->bits[pos]);
    }
}

void charArr2Num(Num *raw, char *charArr){
    int index = 0;
    raw->length = 0;
    while(charArr[index++] != '\0');
    while(index--){
        if(charArr[index] >= '0' && charArr[index] <= '9')
            raw->bits[raw->length++] = charArr[index] - '0';
    }
}

int main(){
    Num a, b;
    char charArr[MAX_BIT];

    scanf("%s", charArr);
    charArr2Num(&a, charArr);

    scanf("%s", charArr);
    charArr2Num(&b, charArr);

    addNum(&a, &b);
    printNum(&a);
}