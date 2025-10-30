#include <stdio.h>

void add(int* n){
    ++*n;
}

int main (){

    int x = 1;

    add(&x);

    printf("%d", x);

    return 0;
}