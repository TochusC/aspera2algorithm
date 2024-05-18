#include <stdio.h>
#include <stdbool.h>

#define MAX_BIT 100010


typedef struct {
    char bits[MAX_BIT];
    bool isNegative;
    int length;
} Num;


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


void printNum( Num *  num){
    if(num->isNegative){
        printf("-");
    }
    for(int pos = num->length - 1; pos >= 0; pos--){
        printf("%c", '0' + num->bits[pos]);
    }
}



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

void copyNum(Num *a, Num *b){
    a->isNegative = b->isNegative;
    a->length = b->length;
    for(int index = 0; index < a->length; index++){
        a->bits[index] = b->bits[index];
    }
}

void multiNum(Num *a, Num *b){
    Num result, temp;

    charArr2Num(&result, "0");

    for(int bIndex = 0; bIndex < b->length; bIndex++){

        charArr2Num(&temp, "0");

        if(b->bits[bIndex] == 0){
            continue;
        }
        else{
            for(int index = 0; index < bIndex; index++){
                temp.bits[index] = 0;
            }

            int carry = 0;

            for(int aIndex = 0; aIndex < a->length; aIndex++){
                temp.bits[aIndex + bIndex] = a->bits[aIndex] * b->bits[bIndex] + carry;
                carry = temp.bits[aIndex + bIndex] / 10;
                temp.bits[aIndex + bIndex] = temp.bits[aIndex + bIndex] % 10;
            }

            temp.length = a->length + bIndex;

            if(carry){
                temp.bits[temp.length++] = carry;
            }
        }

        addNum(&result, &temp);
    }

    copyNum(a, &result);
}

void divNum(Num *a, Num *b){
    if(isGreaterNum(a, b)){
        copyNum(b, a);
        charArr2Num(a, "0");
    }
    else {
        int initTimes = a->length - b->length;
        char charArr[MAX_BIT];
        charArr[0] = 1;
        int len = 1;
        while(initTimes--){
            charArr[len++] = 0;
        }

        Num min;
        charArr2Num(&min, charArr);
        Num max;
        charArr[len] = 1;
        charArr2Num(&max, charArr);
    }
}

int main(){
    Num a, b;
    char charArr[MAX_BIT];

    scanf("%s", charArr);
    charArr2Num(&a, charArr);

    scanf("%s", charArr);
    charArr2Num(&b, charArr);

    multiNum(&a, &b);
    printNum(&a);
}