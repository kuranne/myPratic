#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *chardynamic() {
    size_t size = 2;
    char *str = (char*)calloc(size, sizeof(char));
    if (str == NULL) {return NULL;}

    int c;
    size_t lengt = 0;

    while((c = getchar()) != '\0' && c != EOF && c != ' '){
        if (lengt == size - 1){
            size *= 2;
            char *temp = (char*)realloc(str, size);
            if (temp == NULL) {free(str); return NULL;}

            str = temp;
        }
        str[lengt++] = c;
    }
    str[lengt] = '\0';
    
    char *fnstr = (char*)realloc(str, lengt + 1);
    return (fnstr == NULL)?str:fnstr;
}

int main(){
    char *input = chardynamic();
    int i = 0, k, answer = 0;
    scanf("%d", &k);
    for (i = 0; i < (int)strlen(input) && input[i] != '\0'; i++){
        answer += (input[i] - '0');
    }
    free(input);

    answer *= k;

    while (answer > 9){
        int temp = 0;
        while (answer > 0){
            temp += answer %10;
            answer /= 10;
        }
        answer = temp;
    }
    printf("%d", answer);
    return 0;
}