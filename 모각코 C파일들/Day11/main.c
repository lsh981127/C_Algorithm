#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int factorial(int f)
{
    int answer = 1;
    for(int i = f; i>=1 ;i--)
        answer *= i;

    printf("���丮�� ���� %d�Դϴ�\n", answer);


}
int main()
{
    int x;
    printf("���ϰ� ���� ���丮�� ������ �Է����ּ��� :");
    scanf("%d", &x);
    factorial(x);
    return 0;
}

