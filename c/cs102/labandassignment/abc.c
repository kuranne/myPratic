#include <stdio.h>

int main(){
    int i, n[3], chk = 1, cache;
    char abc[3];
    scanf("%d%d%d%s", &n[0], &n[1], &n[2], abc);
    while(chk){
        for(i=0; i<3; i++){
            if(i!=2 && n[i] < n[i+1]){
                cache = n[i]; n[i] = n[i+1]; n[i+1] = cache; 
                chk = 1; break;
            }else if(i==2 && n[i] > n[i-1]){
                cache = n[i]; n[i] = n[i-1]; n[i-1] = cache; 
                chk = 1; break;
            }
            else{chk = 0;}
        }
    }
    
    for(i=0; i<3; i++){
        switch (abc[i]){
            case('A'):
                printf("%d ", n[2]); break;
            case('B'):
                printf("%d ", n[1]); break;
            case('C'):
                printf("%d ", n[0]); break;
        }
    }
    printf("\n");
    return 0;
}