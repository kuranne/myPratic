#include <stdio.h>

int main(){
    int n = 6, i, j, check = 0;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if( i+j > 8){
                check+=1;
            }
        }
    }
    printf("%d\n", check);
    return 0;
}