#include <stdio.h>

int main(){
    int i, j, m, n;
    scanf("%d%d", &m,&n);
    for(i=0; i<m; i++){
        for(j=0;j<n;j++){
            printf("%s", (i==0||i==m-1)?"*":(j==0||j==n-1)?"*":" ");
        }
        printf("\n");
    }
    return 0;
}