#include <stdio.h>

int main(){
    int data[10], i ,maxi;
    for(i = 0; i<10; i++){
        scanf("%d", &data[i]);
    }
    for(i = 0; i<10; i++){
        if(i==0){maxi = data[i];}
        if(maxi < data[i]){maxi = data[i];}
    }
    printf("Maximum number: %d\n", maxi);
    
    return 0;
}