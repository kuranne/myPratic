#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* cdynamicin(){
  // init buffer
  size_t size = 2;
  char *str = (char*)calloc(size, sizeof(char));
  if (str == NULL) {return NULL;}

  int c;
  size_t legt = 0;

  // getchar is a function to recive char from std input
  while ((c = getchar()) != '\n' && c != EOF) {
    if (legt == size - 1){

      size*=2;
      char *temp = (char*)realloc(str, size); //resize the memory

      if(temp == NULL){free(str); return NULL;}

      str = temp;
    }
    str[legt++] = c;
  }
  str[legt] = '\0'; // add null at the end of array, i don't know why but they recommend.
  char *fnstr = (char*)realloc(str, legt + 1); // plus size one more for efficiency

  return (fnstr == NULL)?str:fnstr;
}

int main(){
  char *trys =cdynamicin();
  printf("%s, %lu\n", trys, strlen(trys)); //strlen output as unsign long
  free(trys);
  return 0;
}