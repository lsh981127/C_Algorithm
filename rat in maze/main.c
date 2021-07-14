#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACKSIZE 100
#define MAX_MAZESIZE 100

typedef struct {
    int x;
    int y;
}position;

position stack[STACKSIZE];
position current_cell = { 1, 1 };                      //현재 위치를 나타내는 구조체 변수 선언
position not_path_found = { -1, -1 };                   // pop실행 시에 스택이 비었을 때(더 이상 진행이 불가능할 떄) 반환값
bool reach_goal = false, all_cell_marked = false;              //길을 찾거나 못 찾았을 때 사용되는 변수 선언
int top = -1, x_big = 0, y_big = 0;                                   //스택 크기와 미로의 크기 변수 선언
int maze[MAX_MAZESIZE][MAX_MAZESIZE] = { 0, }, mark[MAX_MAZESIZE][MAX_MAZESIZE] = { 0, };   //미로와 지나간 길을 표시할 이차원 배열 선언

void ReadFile()                   // 파일을 읽어서 maze에 저장
{
    int i = 0, temp = 0;
    char fdata;
    FILE* fp;
    fp = fopen("maze.txt", "r");
    while (1)
    {
        int j = 0;
        while (1)
        {
            fdata = fgetc(fp);
            if (fdata == '\n' || fdata == EOF)
                break;
            maze[i][j] = (int)(fdata - '0');
            j++;
            temp = j;
        }
        i++;
        if (fdata == EOF)
            break;
    }
    x_big = temp; y_big = i;
    fclose(fp);
}

void PrintMaze()
{
    int i, j;
    for (i = 0; i < y_big; i++)
    {
        for (j = 0; j < x_big; j++)
            printf("%d ", maze[i][j]);
        printf("\n");
    }
}

bool IsEmpty()
{
    if (top < 0)
        return true;
    else
        return false;
}

bool IsFull()
{
    if (top >= STACKSIZE - 1)
        return true;
    else
        return false;
}

void push(int a, int b)
{
    if (IsFull() == true)
        printf("스택이 가득 찼습니다.\n");
    else
    {
        top++;
        stack[top].x = a;
        stack[top].y = b;
    }
}

position pop()
{
    if (IsEmpty() == true)
        return not_path_found;
    else
        return stack[top--];
}

void PrintStack()
{
    for (int i = 0; i <= top; i++)
        printf("(%d,%d)\n", stack[i].x, stack[i].y);
}

void FindPath()
{
    mark[current_cell.y][current_cell.x] = 1;

    if (current_cell.x == (x_big - 2) && current_cell.y == (y_big - 2))                                        //길을 찾았을 때 reach_goal을 true로 바꾼 후 함수 반환
    {
        push(current_cell.x, current_cell.y);
        reach_goal = true;
        return;
    }

    if (maze[current_cell.y][current_cell.x + 1] == 0 && mark[current_cell.y][current_cell.x + 1] == 0)         //오른쪽
    {
        push(current_cell.x, current_cell.y);
        current_cell.x += 1;
        FindPath();
    }
    else if (maze[current_cell.y + 1][current_cell.x] == 0 && mark[current_cell.y + 1][current_cell.x] == 0)    //아래쪽
    {
        push(current_cell.x, current_cell.y);
        current_cell.y += 1;
        FindPath();
    }
    else if (maze[current_cell.y][current_cell.x - 1] == 0 && mark[current_cell.y][current_cell.x - 1] == 0)    //왼쪽
    {
        push(current_cell.x, current_cell.y);
        current_cell.x -= 1;
        FindPath();
    }
    else if (maze[current_cell.y - 1][current_cell.x] == 0 && mark[current_cell.y - 1][current_cell.x] == 0)    //위쪽
    {
        push(current_cell.x, current_cell.y);
        current_cell.y -= 1;
        FindPath();
    }
    else                         //어느 쪽으로도 갈 수 없을 때 pop 실행 (이전 위치로 되돌아감)
    {
        current_cell = pop();
        if (current_cell.x == not_path_found.x && current_cell.y == not_path_found.y)      //pop실행을 한 후, 반환값이 not_path_found랑 같으면(길이 존재하지 않을 때) all_cell_marked를 true로 바꾼 후 함수 반환
        {
            all_cell_marked = true;
            return;
        }
        FindPath();
    }
}

void PrintResult()
{
    if (reach_goal == true)
    {
        printf("path found!\n");
        PrintStack();
    }
    else
        printf("no path exist\n");
}

int main()
{
    ReadFile();
    PrintMaze();
    FindPath();
    PrintResult();
    return 0;
}
