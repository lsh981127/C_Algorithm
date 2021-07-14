#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readfile();
void printcls();
void printmine();
void AddClass(int a);
void AddMine();



struct class {
    char class_name[50];  //���� �̸� 3
    char prof_name[10];   //������ ���� 4
    char class_number[30];  //���¹�ȣ 2
    char time[50];          //�ð� 5
    char room[30];          //���ǽ� 6
    char year[10];          //�г�  1
    int gpa;                //���� 7

};

int cls_num = 0;
int mine_num = 0;
int input_class_number[20];
int k[20];
struct class cls[30];
struct class mine[30];

void readfile() //���� �б�
{
    FILE* fp;
    fp = fopen("classes.txt", "r");
    while (EOF != fscanf(fp, "%s %s %s %s %s %s %d", &cls[cls_num].year, &cls[cls_num].class_number, &cls[cls_num].class_name, &cls[cls_num].prof_name, &cls[cls_num].time, &cls[cls_num].room, &cls[cls_num].gpa))
    {
        cls_num++;
    }
    fclose(fp);
}

void printcls()  //��ü �ð�ǥ ���
{
    for (int i = 0; i < cls_num; i++)
        printf("�г� :%s\n�м����¹�ȣ :%s\n������� :%s\n������ :%s\n����/�ð� :%s\n���ǽ� :%s\n���� :%d\n\n\n", cls[i].year, cls[i].class_number, cls[i].class_name, cls[i].prof_name, cls[i].time, cls[i].room, cls[i].gpa);
}
void printmine() //�� �ð�ǥ ���
{
    for (int i = 0; i < cls_num; i++)
        printf("�г� : %s\n�м����¹�ȣ : %s\n������� : %s\n������ : %s\n����/�ð� : %s\n���ǽ� : %s\n���� : %d\n\n\n", mine[i].year, mine[i].class_number, mine[i].class_name, mine[i].prof_name, mine[i].time, mine[i].room, mine[i].gpa);
}

void AddClass()   //���� �߰� �Լ�
{
    char i;
loop:
    printf("������ �߰��Ͻðڽ��ϱ�? (y/n)\n");
    scanf("%c", &i);
    if (i == 'y') {
        printf("���� ��� �г��� �Է����ּ���\n");
        scanf("%s", &cls[cls_num].year);
        printf("�м����¹�ȣ�� �Է��ϼ���\n");
        scanf("%s", &cls[cls_num].class_number);
        printf("��������� �Է����ּ���\n");
        scanf("%s", &cls[cls_num].class_name);
        printf("�������� �Է����ּ���\n");
        scanf("%s", &cls[cls_num].prof_name);
        printf("�ð��� �Է����ּ���\n");
        scanf("%s", &cls[cls_num].time);
        printf("���ǽ��� �Է����ּ���\n");
        scanf("%s", &cls[cls_num].room);
        printf("������ �Է����ּ���\n");
        scanf("%d", &cls[cls_num].gpa);
        rewind(stdin);
        cls_num++;
        goto loop;
    }
    else
        printcls();

}


void AddMine()  // ���ſ� ����
{
    for (int i = 0; i < cls_num; i++) {
        if (strcmp(input_class_number, cls[i].class_number) == 0) {
            mine[mine_num] = cls[i];
            mine_num++;
        }
    }
}

void sortbyClassNumber(struct class* a, int x)    //�м����·�����
{
    struct class temp;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x - (i + 1); j++)
        {
            if (strcmp(a[j].class_number, a[j + 1].class_number) > 0)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void sortbyProfessor(struct class* a, int x)  //������ �̸����� ����
{
    struct class temp;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x - (i + 1); j++)
        {
            if (strcmp(a[j].prof_name, a[j + 1].prof_name) > 0)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}


void sortbyClassName(struct class* a, int x)      //�����̸����� ����
{
    struct class temp;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x - (i + 1); j++)
        {
            if (strcmp(a[j].class_name, a[j + 1].class_name) > 0)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int menu1, menu2;
    char a;
    printf("�ð�ǥ �����⸦ �����մϴ�.\n");
    readfile();
    printf("���� �ҷ����� �Ϸ�\n");

    AddClass();

point1:     //�� �ð�ǥ�� ���� �߰�
    printf("�� �ð�ǥ�� ������ �߰��Ͻðڽ��ϱ�? (y/n)\n");
    scanf(" %c", &a);

    if (a == 'y') {
        printf("�м���ȣ�� �Է��ϼ���\n");
        scanf(" %s", &input_class_number);
        AddMine();
        goto point1;
    }
    else if (a == 'n') {
    POINT2:

        printf("��ü�ð�ǥ����(�м���ȣ��)=1, ��ü�ð�ǥ����(�����Լ�)=2, ��ü�ð�ǥ����(������)=3\n���νð�ǥ����(�м���ȣ��)=4, ���νð�ǥ����(�����Լ�)=5, ���νð�ǥ����(������)=6\n ");
        scanf(" %d", &menu1);
        switch (menu1)
        {
        case 1:
            sortbyClassNumber(cls, cls_num);
            printf("��ü�ð�ǥ����(�м���ȣ��)\n");
            printcls();
            break;

        case 2:
            sortbyProfessor(cls, cls_num);
            printf("��ü�ð�ǥ����(�����̸���)\n");
            printcls();
            break;
        case 3:
            sortbyClassName(cls, cls_num);
            printf("��ü�ð�ǥ����(������)\n");
            printcls();
            break;
        case 4:
            sortbyClassNumber(mine, mine_num);
            printf("���νð�ǥ����(�м���ȣ��)\n");
            printmine();
            break;
        case 5:
            sortbyProfessor(mine, mine_num);
            printf("���νð�ǥ����(�����̸���)\n");
            printmine();
            break;
        case 6:
            sortbyClassName(mine, mine_num);
            printf("���νð�ǥ����(������)\n");
            printmine();
            break;
        }
    }
    printf("\n����Ͻðڽ��ϱ�? (y/n)");
    scanf(" %c", &menu2);
    if (menu2 == 'y') {
        goto POINT2;
    }
    else if (menu2 == 'n') {
        return 0;
    }
}


