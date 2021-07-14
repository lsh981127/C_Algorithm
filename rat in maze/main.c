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
position current_cell = { 1, 1 };                      //���� ��ġ�� ��Ÿ���� ����ü ���� ����
position not_path_found = { -1, -1 };                   // pop���� �ÿ� ������ ����� ��(�� �̻� ������ �Ұ����� ��) ��ȯ��
bool reach_goal = false, all_cell_marked = false;              //���� ã�ų� �� ã���� �� ���Ǵ� ���� ����
int top = -1, x_big = 0, y_big = 0;                                   //���� ũ��� �̷��� ũ�� ���� ����
int maze[MAX_MAZESIZE][MAX_MAZESIZE] = { 0, }, mark[MAX_MAZESIZE][MAX_MAZESIZE] = { 0, };   //�̷ο� ������ ���� ǥ���� ������ �迭 ����

void ReadFile()                   // ������ �о maze�� ����
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
        printf("������ ���� á���ϴ�.\n");
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

    if (current_cell.x == (x_big - 2) && current_cell.y == (y_big - 2))                                        //���� ã���� �� reach_goal�� true�� �ٲ� �� �Լ� ��ȯ
    {
        push(current_cell.x, current_cell.y);
        reach_goal = true;
        return;
    }

    if (maze[current_cell.y][current_cell.x + 1] == 0 && mark[current_cell.y][current_cell.x + 1] == 0)         //������
    {
        push(current_cell.x, current_cell.y);
        current_cell.x += 1;
        FindPath();
    }
    else if (maze[current_cell.y + 1][current_cell.x] == 0 && mark[current_cell.y + 1][current_cell.x] == 0)    //�Ʒ���
    {
        push(current_cell.x, current_cell.y);
        current_cell.y += 1;
        FindPath();
    }
    else if (maze[current_cell.y][current_cell.x - 1] == 0 && mark[current_cell.y][current_cell.x - 1] == 0)    //����
    {
        push(current_cell.x, current_cell.y);
        current_cell.x -= 1;
        FindPath();
    }
    else if (maze[current_cell.y - 1][current_cell.x] == 0 && mark[current_cell.y - 1][current_cell.x] == 0)    //����
    {
        push(current_cell.x, current_cell.y);
        current_cell.y -= 1;
        FindPath();
    }
    else                         //��� �����ε� �� �� ���� �� pop ���� (���� ��ġ�� �ǵ��ư�)
    {
        current_cell = pop();
        if (current_cell.x == not_path_found.x && current_cell.y == not_path_found.y)      //pop������ �� ��, ��ȯ���� not_path_found�� ������(���� �������� ���� ��) all_cell_marked�� true�� �ٲ� �� �Լ� ��ȯ
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
