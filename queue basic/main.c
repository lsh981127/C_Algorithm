#include <stdio.h>
#include <stdlib.h>
#define Queuesize 6

int queue[Queuesize] = {0};
int front = 0, rear = 0;
int item;

void AddQ(int item)
{
    if(rear+1 == front)
        printf("queue full\n");
    else
        queue[rear = (rear+1) % Queuesize] = item;

}
void DeleteQ()
{
    if(front == rear)
        printf("queue is empty\n\n");
    else
        queue[front = (front + 1) % Queuesize] = 0;

}
void printQ()
{
    for(int i =0; i < Queuesize; i++)
        printf(" %d", queue[i]);
    printf("\n\n");
}
int main()
{
    DeleteQ();
    printQ();

    AddQ(1);
    AddQ(2);
    AddQ(3);
    printQ(queue);
    DeleteQ();
    DeleteQ();
    printQ();

    return 0;
}
