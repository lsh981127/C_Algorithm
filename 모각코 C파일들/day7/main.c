#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 0;
    printf("정수를 입력하세요:");      //asd
    scanf("%d", &num1);

    for(int i = 1; i <= num1; i++) {
        if(i % 3 != 0)
            printf(" %d", i);
        else
            printf(" *");
    }

    return 0;
}
