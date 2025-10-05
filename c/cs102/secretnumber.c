#include "configstdc.h" // stdio stdlib string math, pragma optimizer

char *dynamicin(){
    size_t size = 2, length = 0;
    char *buff = (char*)calloc(size, sizeof(char));
    if (buff == NULL){return NULL;}
    int c;

    while ((c = getchar()) != '\n' && c != EOF && c != ' '){
        if (length == size - 1) {
            size *= 2;
            char *temp = (char*)realloc(buff, size);
            if (temp == NULL){free(buff); return NULL;}
            buff = temp;
        }
        buff[length++] = c;
    }
    if (length == 0){free(buff); return NULL;}
    buff[length] = '\0';
    char *fnstr = (char*)realloc(buff, length + 1);
    return (fnstr == NULL)?buff:fnstr;    
}

int chktext(char text[]) {
    int i, t;
    for (i=0; i < (int)strlen(text) && (t = text[i]) != '\0' && t != EOF; i++){
        if (t > '9') {return 1;}
    }
    return 0;
}

signed main(const int argc, char *argv[]){
    int dynamic = 0;
    char *numbers = (argc == 2)?argv[1]:dynamicin();
    if(numbers == NULL){fprintf(stderr, "Failed to read input."); return 1;}
    int i, len = strlen(numbers), ans = 0, temp;
    if (len % 2 != 0 || chktext(numbers)){fprintf(stderr, "INVALID TEXT\n"); return 1;}
    for (i = 0; i < len && numbers[i] != '\0'; i++){
        if (i%2 == 0){temp = numbers[i] - '0';}
        else { ans += (int)(pow(((double)(numbers[i] - '0') - temp), 4.0));}
    }

    printf("%d\n", ans);
    if (argc != 2){free(numbers);}
    return 0;
}