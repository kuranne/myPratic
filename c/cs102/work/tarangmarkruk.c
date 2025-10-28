#include <stdio.h>

int main(){
    for(int i=0; i < 8; i++){
        printf("row: %d     ", i+1);
        for(int j=0; j < 8; j++){
            printf("%c ", (i%2==0)?(j%2 == 0)?'X':'O':(j%2 == 0)?'O':'X');
        }
        printf("\n");
    }
    return 0;
}