#include <stdio.h>

int main(){
    char buff[101];
    int i, sum = 0, k;
    scanf("%s %d", buff, &k);
    for(i = 0; i < 100 && buff[i] != '\0'; i++){
        sum += (buff[i]-'0');
    }
    sum *= k;
    while(sum > 9){
        int nsum = 0;
        while(sum > 0){
            nsum += sum%10;
            sum /= 10;
        }
        sum = nsum;
    }
    printf("%d\n", sum);
    return 0;
}