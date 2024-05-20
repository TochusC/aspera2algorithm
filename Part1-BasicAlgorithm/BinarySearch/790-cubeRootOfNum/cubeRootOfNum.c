#include <stdio.h>

double abs(double num){
    return num < 0 ? -num : num;
}

int main(){
    double num;

    scanf("%lf", &num);

    double min = -100, max = 100;

    while(min < max){
        double mid = (min + max) / 2;

        if(mid * mid * mid < num){
            min = mid;
        }
        else{
            max = mid;
        }

        if(max - min < 0.0000001){
            break;
        }
    }

    printf("%lf", min);
}