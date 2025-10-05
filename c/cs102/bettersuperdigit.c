#pragma GCC optimize("03", "unroll-loops")
#pragma GCC traget("avx2")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cydynamicin(){
    size_t size = 2, lenght = 0;
    int c;
    char *buff = (char*)calloc(size, sizeof(char));
    if (buff == NULL){return NULL;}

    while ((c=getchar()) != '\n' && c != EOF && c!=' ') {
        if (lenght == size - 1){
            size *= 2;
            char *temp = (char*)realloc(buff, size);
            if(temp==NULL){free(buff); return NULL;}
            buff = temp;
        }        
        buff[lenght++] = c;
    }

    buff[lenght] = '\0';
    char *str = (char*)realloc(buff, lenght+1);
    return (str == NULL)?buff:str;
}

signed main(){
    char *number = cydynamicin();
    if(number == NULL) {return 1;}
    int i, ans = 0, k;
    scanf("%d", &k);

    for (i=0; i < (int)(strlen(number)) && number[i] != '\0'; i++){
        ans += number[i] - '0';
    }
    
    ans *= k;
    free(number);

    int temp;
    while (ans > 9){
        temp = 0;
        while (ans > 0){
            temp += ans%10;
            ans /= 10;
        }
        ans = temp;
    }

    printf("%d\n", ans);
    return 0;
}