#include <stdio.h>
#include <stdlib.h>

int main(){
    int *test = (int*)calloc(2, sizeof(int));
    printf("%d", test[0]);
    return 0;
}