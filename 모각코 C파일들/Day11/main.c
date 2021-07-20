#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int factorial(int f)
{
    int answer = 1;
    for(int i = f; i>=1 ;i--)
        answer *= i;

    printf("팩토리얼 값은 %d입니다\n", answer);


}
int main()
{
    int x;
    printf("구하고 싶은 팩토리얼 정수를 입력해주세요 :");
    scanf("%d", &x);
    factorial(x);
    return 0;
}

