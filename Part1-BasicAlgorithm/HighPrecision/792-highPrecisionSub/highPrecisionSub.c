#include <stdio.h>
#include <stdbool.h>

#define MAX_BIT 100010


typedef struct {
    char bits[MAX_BIT];
    bool isNegative;
    int length;
} Num;

void addNum(Num *  a,  Num *  b){
    if(a->isNegative == b->isNegative){
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
}

bool isGreaterNum( Num *  a,  Num *  b){
    if(a->isNegative == b->isNegative){
        bool isNegative = a->isNegative;

        if(a->length < b->length){
            return isNegative?false:true;
        }
        else if(b->length < a->length){
            return isNegative?true:false;
        }
        else{
            for(int index = a->length - 1; index >= 0; index--){
                if(a->bits[index] < b->bits[index]){
                    return isNegative?false:true;
                }
                else if(b->bits[index] < a->bits[index]){
                    return isNegative?true:false;
                }
            }
            return false;
        }
    }
    else{
        if(a->isNegative){
            return true;
        }
        else{
            return false;
        }
    }
}

void subNum(Num *  a, Num *b){
    if(a->isNegative != b->isNegative){
        a->isNegative = !a->isNegative;
        addNum(a, b);
        a->isNegative = !b->isNegative;
    }
    else{
        if(isGreaterNum(a, b)){
            subNum(b, a);
            a->length = b->length;
            for(int index = 0; index < a->length; index++){
                a->bits[index] = b->bits[index];
            }
            a->isNegative = !a->isNegative;
        }
        else{
            int index, borrow = 0;
            for(index = 0; index < a->length && index < b->length; index++){
                a->bits[index] = a->bits[index] - b->bits[index] + borrow;
                if(a->bits[index] < 0){
                    borrow = -1;
                    a->bits[index] += 10;
                }
                else{
                    borrow = 0;
                }
            }
            while(borrow != 0){
                a->bits[index] = a->bits[index] + borrow;
                borrow = 0;
                if(a->bits[index] < 0){
                    borrow = -1;
                    a->bits[index] += 10;
                }
                index++;
            }
            while(a->bits[a->length-1] == 0 && a->length > 1){
                a->length--;
            }
        }
    }
}

void printNum( Num *  num){
    if(num->isNegative){
        printf("-");
    }
    for(int pos = num->length - 1; pos >= 0; pos--){
        printf("%c", '0' + num->bits[pos]);
    }
}

void charArr2Num(Num *raw,  char *  charArr){
    int index = 0;
    raw->length = 0;
    while(charArr[index++] != '\0');
    while(index--){
        if(charArr[index] >= '0' && charArr[index] <= '9')
            raw->bits[raw->length++] = charArr[index] - '0';
    }
    raw->isNegative = false;
}

int main(){
    Num a, b;
    char charArr[MAX_BIT];

    scanf("%s", charArr);
    charArr2Num(&a, charArr);

    scanf("%s", charArr);
    charArr2Num(&b, charArr);

    subNum(&a, &b);
    printNum(&a);
}