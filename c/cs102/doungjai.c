#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, ques, ans;
    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &ques);
        ans += ((ques%2==0)?6:5);
    }
    printf("%d\n", ans);

    return 0;
}