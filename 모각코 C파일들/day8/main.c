#include <stdio.h>
#include <stdlib.h>

int main()
{

    int score[5] = {0,};
    for(int i = 0;i<5;i++){
        printf("%d�� �⸻��� ���� �Է�:", i+1);
        scanf("%d", &score[i]);
    }
    int max = score[0];
    for(int i = 1;i<5;i++){
        if(max <= score[i])
            max = score[i];
        else
            max = max;
}
    printf("�ִ� :%d\n", max);
    return 0;
}
