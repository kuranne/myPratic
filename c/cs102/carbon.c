#include <stdio.h>

int main(){
    int n, water;
    double carbon[3] = {0.0003, 0.0001, 0.0004};
    scanf("%d%d", &water, &n);
    if(n > 3 || n < 1){
        printf("Invalid Input\n");
        return 1;
    }
    else{
        printf("%lf\n", carbon[n-1] * (double)water);
    }
    return 0;
}