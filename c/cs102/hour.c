#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, *ans = (int*)calloc(3,sizeof(int));
    scanf("%d", &n);
    ans[0] = n % 24;
    ans[1] = n / 24;
    ans[2] = ans[1] / 7;
    ans[1] %= 7;
    printf("%d\n%d\n%d\n", ans[2], ans[1], ans[0]);
    free(ans);
    return 0;
}