#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readfile();
void printcls();
void printmine();
void AddClass(int a);
void AddMine();



struct class {
    char class_name[50];  //강의 이름 3
    char prof_name[10];   //교수님 성함 4
    char class_number[30];  //강좌번호 2
    char time[50];          //시간 5
    char room[30];          //강의실 6
    char year[10];          //학년  1
    int gpa;                //학점 7

};

int cls_num = 0;
int mine_num = 0;
int input_class_number[20];
int k[20];
struct class cls[30];
struct class mine[30];

void readfile() //파일 읽기
{
    FILE* fp;
    fp = fopen("classes.txt", "r");
    while (EOF != fscanf(fp, "%s %s %s %s %s %s %d", &cls[cls_num].year, &cls[cls_num].class_number, &cls[cls_num].class_name, &cls[cls_num].prof_name, &cls[cls_num].time, &cls[cls_num].room, &cls[cls_num].gpa))
    {
        cls_num++;
    }
    fclose(fp);
}

void printcls()  //전체 시간표 출력
{
    for (int i = 0; i < cls_num; i++)
        printf("학년 :%s\n학수강좌번호 :%s\n교과목명 :%s\n교원명 :%s\n요일/시간 :%s\n강의실 :%s\n학점 :%d\n\n\n", cls[i].year, cls[i].class_number, cls[i].class_name, cls[i].prof_name, cls[i].time, cls[i].room, cls[i].gpa);
}
void printmine() //내 시간표 출력
{
    for (int i = 0; i < cls_num; i++)
        printf("학년 : %s\n학수강좌번호 : %s\n교과목명 : %s\n교원명 : %s\n요일/시간 : %s\n강의실 : %s\n학점 : %d\n\n\n", mine[i].year, mine[i].class_number, mine[i].class_name, mine[i].prof_name, mine[i].time, mine[i].room, mine[i].gpa);
}

void AddClass()   //과목 추가 함수
{
    char i;
loop:
    printf("과목을 추가하시겠습니까? (y/n)\n");
    scanf("%c", &i);
    if (i == 'y') {
        printf("과목 대상 학년을 입력해주세요\n");
        scanf("%s", &cls[cls_num].year);
        printf("학수강좌번호를 입력하세요\n");
        scanf("%s", &cls[cls_num].class_number);
        printf("교과목명을 입력해주세요\n");
        scanf("%s", &cls[cls_num].class_name);
        printf("교원명을 입력해주세요\n");
        scanf("%s", &cls[cls_num].prof_name);
        printf("시간을 입력해주세요\n");
        scanf("%s", &cls[cls_num].time);
        printf("강의실을 입력해주세요\n");
        scanf("%s", &cls[cls_num].room);
        printf("학점을 입력해주세요\n");
        scanf("%d", &cls[cls_num].gpa);
        rewind(stdin);
        cls_num++;
        goto loop;
    }
    else
        printcls();

}


void AddMine()  // 내거에 저장
{
    for (int i = 0; i < cls_num; i++) {
        if (strcmp(input_class_number, cls[i].class_number) == 0) {
            mine[mine_num] = cls[i];
            mine_num++;
        }
    }
}

void sortbyClassNumber(struct class* a, int x)    //학수강좌로정렬
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

void sortbyProfessor(struct class* a, int x)  //교수님 이름으로 정렬
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


void sortbyClassName(struct class* a, int x)      //강좌이름으로 정렬
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
    printf("시간표 생성기를 시작합니다.\n");
    readfile();
    printf("파일 불러오기 완료\n");

    AddClass();

point1:     //내 시간표에 과목 추가
    printf("내 시간표에 과목을 추가하시겠습니까? (y/n)\n");
    scanf(" %c", &a);

    if (a == 'y') {
        printf("학수번호를 입력하세요\n");
        scanf(" %s", &input_class_number);
        AddMine();
        goto point1;
    }
    else if (a == 'n') {
    POINT2:

        printf("전체시간표보기(학수번호순)=1, 전체시간표보기(교수님순)=2, 전체시간표보기(과목명순)=3\n개인시간표보기(학수번호순)=4, 개인시간표보기(교수님순)=5, 개인시간표보기(과목명순)=6\n ");
        scanf(" %d", &menu1);
        switch (menu1)
        {
        case 1:
            sortbyClassNumber(cls, cls_num);
            printf("전체시간표보기(학수번호순)\n");
            printcls();
            break;

        case 2:
            sortbyProfessor(cls, cls_num);
            printf("전체시간표보기(교수이름순)\n");
            printcls();
            break;
        case 3:
            sortbyClassName(cls, cls_num);
            printf("전체시간표보기(과목명순)\n");
            printcls();
            break;
        case 4:
            sortbyClassNumber(mine, mine_num);
            printf("개인시간표보기(학수번호순)\n");
            printmine();
            break;
        case 5:
            sortbyProfessor(mine, mine_num);
            printf("개인시간표보기(교수이름순)\n");
            printmine();
            break;
        case 6:
            sortbyClassName(mine, mine_num);
            printf("개인시간표보기(과목명순)\n");
            printmine();
            break;
        }
    }
    printf("\n계속하시겠습니까? (y/n)");
    scanf(" %c", &menu2);
    if (menu2 == 'y') {
        goto POINT2;
    }
    else if (menu2 == 'n') {
        return 0;
    }
}


