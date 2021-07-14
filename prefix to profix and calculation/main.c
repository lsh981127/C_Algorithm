#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100
#define EOS 0

int stack[MAXSTACK];
int top = -1;


char push(char token)
{
    if(top == MAXSTACK -1)
        printf("������ ����á���ϴ�.\n");
    else
        stack[++top] = token;

}
int pop(){
    if(top<0)
        printf("������ ������ϴ�\n");
    else
        stack[top--];

}
int isDigit(char token)   //�������� �ƴ��� �Ǻ�
{
    if('0' <= token && token <= '9')
        return 1;
    else
        return 0;
}
int getPriority(char token)    //infix ������ �켱���� ���
{
    switch(token)
    {
        case '*':
        case '/': return 5;
        case '+':
        case '-': return 1;

    }
}
int stackPriority(char token)    //���ÿ� ����� ������ �켱���� ���
{
    switch(token)
    {
        case '*':
        case '/': return 5;
        case '+':
        case '-': return 2;
    }
}


void convert(char* infix, char* postfix)    //infix ���� postfix�� ��ȯ
{
    int cnt = 0;
    char token;
    push(EOS);
    for(int i = 0; infix[i] != 0; i++)
    {
        token = infix[i];
        if(isDigit(token))
            postfix[cnt++] = token;
        else
        {
            while(stackPriority(stack[top]) >= getPriority(token))
            {
                postfix[cnt++] = pop();

            }
        }

    }
    do
    {
        postfix[cnt++] = pop();
    } while(postfix[cnt-1] != EOS);

}

int evaluate(char* postfix)
{
    char token, op1, op2;
    for(int i=0;postfix[i] != 0; i++)
    {
        token = postfix[i];
        if(isDigit(token))
            push(token-'0');
        else
        {
            op1 = pop(), op2 = pop();
            switch(token)
            {
                case '*': push(op2*op1); break;
                case '/': push(op2/op1); break;
                case '+': push(op2+op1); break;
                case '-': push(op2-op1); break;

            }
        }
    }
    return pop();
}
int calc(char *p){
    int i;
    while (*p){
        if (*p >= '0' && *p <= '9'){
            i = 0;
            do{
                i = i * 10 + *p - '0';
                p++;
            } while (*p >= '0' && *p <= '9');
            push(i);
        }
        else if (*p == '+'){
            push(pop() + pop());
            p++;
        }
        else if (*p == '*'){
            push(pop() * pop());
            p++;
        }
        else if (*p == '-'){
            i = pop();
            push(pop() - i);
            p++;
        }
        else if (*p == '/'){
            i = pop();
            push(pop() / i);
            p++;
        }
        else{
            p++;
        }
    }
    return pop();
}

int main()
{
    char infix[10], postfix[10];
    puts("���� �Է��ϼ���>>");
    scanf("%s", infix);
    convert(infix, postfix);
    printf("postfix >> %s\n", postfix);
    printf("result >> %d\n", evaluate);
    printf("calculation result >> %d\n", calc(postfix));
    return 0;
}
