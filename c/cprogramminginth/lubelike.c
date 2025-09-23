#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n, maxnum;
    scanf("%d", &n);
    int *morei = (int*)malloc(sizeof(int)*n);
    scanf("%d", &morei[0]);
    maxnum = morei[0];

    for(i=1; i<n; i++){
        scanf("%d", &morei[i]);
        if(morei[i] > maxnum) maxnum = morei[i];
    }

    int *count = (int*)calloc(maxnum+1, sizeof(int));

    for(i=0; i<n; i++){
        count[morei[i]]++;
    }

    int *max = (int*)malloc(sizeof(int)*2);
    max[0] = 0;
    max[1] = 0;

    for(i=0; i<=maxnum; i++){
        if(count[i] > max[1]){
            max[0] = i;
            max[1] = count[i];
        }
    }

    printf("%d\n", max[0]);

    free(max);
    free(morei);
    free(count);

    return 0;
}