#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 10, b = 15;
    int* aadr = &a;
    int* badr = &b;

    printf("a�� ���� :%d\n", *aadr);
    printf("a�� �ּҰ��� : %p\n", aadr);

    printf("b�� ���� :%d\n", *badr);
    printf("b�� �ּҰ��� : %p\n", badr);

    int c = *aadr;      //a���� �����صα� ���� ���� ����
    *aadr = *badr;      //�����͸� Ȱ���� ���� ������ ���� �ٲ����� �ּҴ� �״�� ����
    *badr = c;

    printf("�ٲ� �� a�� ���� :%d\n", *aadr);
    printf("�ٲ� �� a�� �ּҰ��� : %p\n", aadr);

    printf("�ٲ� �� b�� ���� :%d\n", *badr);
    printf("�ٲ� �� b�� �ּҰ��� : %p\n", badr);
    return 0;
}
