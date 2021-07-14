#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define STACKSIZE 100
#define MAX_MAZESIZE 100

typedef enum {
    up = 0,
    right,
    down,
    left,
    cnt
}direction;

typedef struct {
    int x;
    int y;
    direction Dir;
}position;

position stack[STACKSIZE];
position agent = { 13, 7 }, current_cell = { 1, 1 }, not_path_found = { -1, -1 };
int top = -1, x_cnt = 15, y_cnt =9;
int maze[MAX_MAZESIZE][MAX_MAZESIZE] = { 0, }, mark[MAX_MAZESIZE][MAX_MAZESIZE] = { 0, };
float value[MAX_MAZESIZE][MAX_MAZESIZE] = { 0, }, temp_value[MAX_MAZESIZE][MAX_MAZESIZE] = { 0, }, r = 1.0f;
bool reach_goal = false, all_cell_marked = false;



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
    {
        printf("배열이 비었습니다.\n");
        return not_path_found;
    }
    else
        return stack[top--];
}

void PrintStack()
{
    for (int i = 0; i <= top; i++)
    {
        if (i != 0 && (i % 10) == 0)
            printf("(%d, %d)\n", stack[i].x, stack[i].y);
        else
            printf("(%d, %d) -> ", stack[i].x, stack[i].y);
    }
}

void RevPrintStack()
{
    for (int i = top; i >= 0; i--)
    {
        if (i != top && i % 10 == 0)
            printf("(%d,%d)\n", stack[i].x, stack[i].y);
        else
            printf("(%d,%d) -> ", stack[i].x, stack[i].y);
    }
}

void value_update()
{
    for (int i = 1; i < y_cnt - 1; i++)
    {
        for (int j = 1; j < x_cnt - 1; j++)
        {
            if (i == 1 && j == 1);
            else if (i == y_cnt - 2 && j == x_cnt - 2);
            else if (maze[i][j] == 0)
            {
                float temp = 0;
                for (direction Dir = up; Dir < cnt; Dir++)
                {
                    switch (Dir)
                    {
                    case up:
                        if (maze[i - 1][j] == 0)
                            temp += (-1 + r * value[i - 1][j]);
                        else
                            temp += (-1 + r * value[i][j]);
                        break;
                    case right:
                        if (maze[i][j + 1] == 0)
                            temp += (-1 + r * value[i][j + 1]);
                        else
                            temp += (-1 + r * value[i][j]);
                        break;
                    case down:
                        if (maze[i + 1][j] == 0)
                            temp += (-1 + r * value[i + 1][j]);
                        else
                            temp += (-1 + r * value[i][j]);
                        break;
                    case left:
                        if (maze[i][j - 1] == 0)
                            temp += (-1 + r * value[i][j - 1]);
                        else
                            temp += (-1 + r * value[i][j]);
                        break;
                    default:
                        break;
                    }
                }
                temp /= 4.0f;
                temp_value[i][j] = temp;
            }
        }
    }
    memcpy(value, temp_value, sizeof(value));
}

void printvalue(int a)
{
    printf("k = %d\n\n", a);
    for (int i = 0; i < y_cnt; i++)
    {
        for (int j = 0; j < x_cnt; j++)
            printf("%.1f\t", value[i][j]);
        printf("\n\n");
    }
    printf("\n");
}

int main()
{
    clock_t start, end;
    start = clock();
    for (int i = 0; i < 15; i++)
    {
        value_update();
        printvalue(i);
    }
    printf("path by RL\n");
    PrintStack();
    end = clock();
    printf("\n걸린 시간 : %.2lf초\n", (float)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
