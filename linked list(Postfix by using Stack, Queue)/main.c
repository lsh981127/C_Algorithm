#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TRUE 1
#define FALSE 0


typedef struct node{
    char data;
    struct node* next;
}Node;

typedef struct list{
    Node* front;
    Node* rear;
    Node* cur;
}List;



int IsEmpty(List* plist){
    if(plist->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void ListInit(List* plist){
    plist->front=NULL;
    plist->cur=NULL;
    plist->rear=NULL;
}



void Push(List* plist, char c){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=c;
    if(IsEmpty(plist)){
        newnode->next=NULL;
        plist->front=newnode;
    }
    else{
        newnode->next=plist->front;
        plist->front=newnode;
    }

}
//스택
char Pop(List* plist)
{
    Node* rnode;
    char rdata;

    if(IsEmpty(plist))
        printf("Stack is Empty!\n");
    else
    {
        rnode=plist->front;
        rdata=plist->front->data;
        plist->front=plist->front->next;
        free(rnode);
        return rdata;
    }
}

void Printlist(List* plist){
    plist->cur=plist->front;
    while(plist->cur!=NULL){
        printf("%c ",plist->cur->data);
        plist->cur=plist->cur->next;
    }
    printf("\n");
}

// 큐
void Insertq(List* plist, char c){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=c;

    if(IsEmpty(plist)){
        newnode->next=NULL;
        plist->front=newnode;
        plist->rear=newnode;
    }
    else{
        newnode->next=NULL;
        plist->rear->next=newnode;
        plist->rear=newnode;
    }
}

char Deleteq(List* plist){
    Node* rnode;
    char rdata;

    if(IsEmpty(plist))        printf("Queue is Empty!\n");
    else{
        rnode=plist->front;
        rdata=plist->front->data;
        plist->front=plist->front->next;
        free(rnode);
        return rdata;
    }

}

void Makelist(List* plist, char arr[]){
    int i;

    for(i=0; i<strlen(arr); i++)   Insertq(plist,arr[i]);
}

int GetPrio(char c)  // 우선순위 정함
{
    switch(c)
    {
        case '-':
        case '+':
        return 1;
        case '*':
        case '/':
        return 5;
    }
    return -1;
}

void Conversion(List* qlist, List* slist){  //변환
    qlist->cur=qlist->front;
    while(qlist->cur!=NULL){
        if(isalpha(qlist->cur->data))   printf("%c ",qlist->cur->data);
        else{
           if(IsEmpty(slist))      Push(slist,qlist->cur->data);
      else{
                   if(GetPrio(qlist->cur->data) > GetPrio(slist->front->data))   Push(slist, qlist->cur->data);
                else{
                    while(!IsEmpty(slist) && GetPrio(qlist->cur->data) <= GetPrio(slist->front->data))   printf("%c ",Pop(slist));
                    Push(slist, qlist->cur->data);
                }
            }
        }
        qlist->cur=qlist->cur->next;
    }

    while(!IsEmpty(slist))   printf("%c ",Pop(slist));
    printf("\n");
}

int main(){
    List stack;
    List queue;
    char arr[20];

    FILE *fp = fopen("index.txt", "r");
    fgets(arr, sizeof(arr), fp);

    printf("-----------Main for stack----------\n");
    printf("a push, b push, c push, pop, d push, e push\n\n");
    ListInit(&stack);
    Push(&stack,'a');
    Push(&stack,'b');
    Push(&stack,'c');
    Printlist(&stack);
    Pop(&stack);
    Push(&stack,'d');
    Push(&stack,'e');
    Printlist(&stack);
    printf("\n\n");

    printf("----------Main for queue----------\n");
    printf("a insert, b insert, deleteq, c insert, d insert\n\n");
    ListInit(&queue);
    Insertq(&queue,'a');
    Insertq(&queue,'b');
    Printlist(&queue);
    Deleteq(&queue);
    Insertq(&queue,'c');
    Insertq(&queue,'d');
    Printlist(&queue);
    printf("\n\n");

    printf("--Main for expression conversion--\n");
    ListInit(&stack);
    ListInit(&queue);
    Makelist(&queue,arr);
    printf("중위표기 : ");
    Printlist(&queue);
    printf("후위표기 : ");
    Conversion(&queue,&stack);
    printf("\n\n");

}
