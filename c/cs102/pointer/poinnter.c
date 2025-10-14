#include <stdio.h>

int main(){
    int n = 1, *ptr = &n, **ptr2 = &ptr;
    printf("%d %d %d\n", **ptr2, *ptr, n);
    printf("%p %p %p\n", *ptr2, ptr, &n);
    printf("%p %p %p\n", ptr2, ptr, &n);
    printf("%p %p %p\n", &ptr2, &ptr, &n);
    return 0;
}