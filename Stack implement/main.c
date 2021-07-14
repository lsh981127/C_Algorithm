#include<stdio.h>
#include <stdbool.h>
#include<string.h>
#define MAX_STACK_SIZE 5

int stk[MAX_STACK_SIZE];
int top=-1;

int IsEmpty(){
    if(top<0)
        return true;
    else
        return false;
    }
int IsFull(){
    if(top>=MAX_STACK_SIZE-1)
        return true;
    else
        return false;
}

void push(int x){
    if(IsFull()==true)
        printf("스택이 가득 찼습니다.");
    else
        stk[++top]=x;
}

int pop(){
    if(IsEmpty()==true)
        printf("스택이 비었습니다.");
    else
        return stk[top--];
}

int main(){

    push(1);
    push(3);
    push(4);
    printf("%d ",pop());
    printf("%d ",pop());
    printf("%d ",pop());
    push(5);
    for(int i=0; i < MAX_STACK_SIZE;i++)
        printf("%d ", stk[i]);
    return 0;
}
