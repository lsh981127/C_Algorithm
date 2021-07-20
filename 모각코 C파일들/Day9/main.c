#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 10, b = 15;
    int* aadr = &a;
    int* badr = &b;

    printf("a의 값은 :%d\n", *aadr);
    printf("a의 주소값은 : %p\n", aadr);

    printf("b의 값은 :%d\n", *badr);
    printf("b의 주소값은 : %p\n", badr);

    int c = *aadr;      //a값을 저장해두기 위한 변수 선언
    *aadr = *badr;      //포인터를 활용해 기존 변수의 값을 바꾸지만 주소는 그대로 유지
    *badr = c;

    printf("바꾼 뒤 a의 값은 :%d\n", *aadr);
    printf("바꾼 뒤 a의 주소값은 : %p\n", aadr);

    printf("바꾼 뒤 b의 값은 :%d\n", *badr);
    printf("바꾼 뒤 b의 주소값은 : %p\n", badr);
    return 0;
}
