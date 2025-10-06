#include <stdio.h>

int main(){
    //initial variable
    int i = 0, ans = 0, temp;
    long long input;
    scanf("%lld", &input);

    while (input > 0){
        if (i%2 == 0){
            temp = (input % 10);
        }
        else {
            ans += (temp - (input % 10))*(temp - (input % 10))*(temp - (input % 10))*(temp - (input % 10));
        }
        input /= 10;
        i++;
    }

    if (i%2 == 0){
        printf("%d\n", ans);
    } else {
        printf("INVALID TEXT\n");
    }
    return 0;
}