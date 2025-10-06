#include <stdio.h>

int main(){
    //initial variable
    int i = 0, temp, ans = 0;
    long long input; // ใช้ long long int เพราะโจทย์ input เลขเกิน int
    scanf("%lld", &input); // %lld is long long int >> ~64bit

    while (input > 0) { // divide until equal 0 แบบว่าดึงตัวหลังสุดออกมาเรื่อยๆจนกว่าจะหมด
        
        if (i%2==0){ 
            temp = input % 10;
        } else {
            ans += (temp - (input % 10))*(temp - (input % 10))*(temp - (input % 10))*(temp - (input % 10)); //(a-b)**4
        }

        input /= 10;
        i++; // for check the length of input
    }

    if (i%2==0){ // if length is not even (not couple) print error
        printf("%d\n", ans);
    } else {
        printf("INVALID TEXT\n");
    }

    return 0;
}
#include <stdio.h>

int main(){
    //initial variable
    int i = 0, ans = 0, temp;
    long long input;
    scanf("%lld", &input);

    while (input > 0){
        if (i%2 == 0){
            temp = (input % 10);
        }
        else {
            ans += (temp - (input % 10))*(temp - (input % 10))*(temp - (input % 10))*(temp - (input % 10));
        }
        input /= 10;
        i++;
    }

    if (i%2 == 0){
        printf("%d\n", ans);
    } else {
        printf("INVALID TEXT\n");
    }
    return 0;
}