#include <stdio.h>
#include <math.h>

int main (){
        int r;
        scanf("%d", &r);
        float a = r*r*3.14;

        if(a>30){
            printf("This is a big circle with size %f\n", a);
        }
        else {
            printf("This is a small circle with size %f\n", a);
        }
        return 0;
}