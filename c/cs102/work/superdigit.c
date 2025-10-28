#include <stdio.h>

int main()
{
    char numbers[101];
    int i, ans = 0, k;
    scanf("%s%d", numbers, &k);

    for (i = 0; i < 101 && numbers[i] != '\0'; i++)
    {
        ans += numbers[i] - '0';
    }
    ans *= k;
    int temp;

    while (ans > 9)
    {
        temp = 0;
        while (ans > 0)
        {
            temp += ans % 10;
            ans /= 10;
        }
        ans = temp;
    }
    printf("%d\n", ans);

    return 0;
}