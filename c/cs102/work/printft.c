#include <stdio.h>

int main(){
    char name[15] = "THAMMASAT", somechar = 'Y';
    int year = 2568;
    float score = 77/3.0;

    printf("%15s\t%15d\t%15c\t%15.3f\n", name, year, somechar, score);
    return 0;
}