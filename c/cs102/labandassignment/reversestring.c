#include <stdio.h>
#include <stdlib.h>

char *dynamicin(){
  size_t size = 2, length = 0;
  char *buff = (char*)calloc(size, sizeof(char));
  if (buff == NULL){return NULL;}
  int c;

  while ((c = getchar()) != '\n' && c != EOF && c != ' '){
    if (length == size - 1){
      size *= 2;
      char *temp = (char*)realloc(buff, size);
      if (temp == NULL){ free(buff); return NULL;}
      buff = temp;
    }
    buff[length++] = c;
  }
  if (length == 0){free(buff); return NULL;}
  buff[length] = '\0';
  char *fnstr = (char*)realloc(buff, length + 1);
  return (fnstr == NULL)?buff:fnstr;
}


signed main(){
  char *input = dynamicin();
  int count = 0;

  while (input[count++]!='\0');

  while (count >= 0){
    printf("%c", input[count - 1]);
    count--;
  }

  printf("\n");
  return 0;
}
