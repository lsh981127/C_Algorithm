#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void max_output(int arr[], int size);

int main()
{
    int data[10] = {0,};
    int *ptr = data;

    printf("�� 10���� �Է����ּ���.");
    for(int i = 0; i<10;i++)
        scanf("%d", &data[i]);

    max_output(ptr, sizeof(data) / sizeof(int));



    return 0;
}

void max_output(int arr[], int size)
{
    int max = arr[0];

    for(int i =1; i<size;i++){
            if(max < arr[i])
                max = arr[i];
    }

    printf("�ִ밪�� %d�Դϴ�.\n", max);

}
