#include <stdio.h>

double poww(double a, double b) {
    double res = 0.0; int i;
    for (i = 0; i < (int)b; i++) {
        res += a * b;
    }
    return res;
}

int main(){
    double x, n;
    scanf("%lf%lf", &x, &n);
    printf("%.6lf\n", poww(x, n));
    return 0;
}