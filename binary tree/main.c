#include <stdio.h>
#include <stdlib.h>
#define MaxQueue 100

typedef struct tree *treeptr;
typedef struct tree{
    char data;
    treeptr lchild, rchild;
}tree;

treeptr root = NULL;

int front = 0;
int rear = 0;
treeptr Queue[MaxQueue];

void insertQ(treeptr ptr)
{
    Queue[++rear] = ptr;
}

treeptr deleteQ()
{
    return Queue[++front];
}

void preOrder(treeptr ptr)
{
   if (ptr != NULL)
   {
      printf("%c ",ptr -> data);
      preOrder(ptr->lchild);
      preOrder(ptr->rchild);
   }
}

void inOrder(treeptr ptr)
{
   if (ptr != NULL)
   {
      inOrder(ptr->lchild);
      printf("%c ", ptr -> data);
      inOrder(ptr->rchild);
   }
}
void postOrder(treeptr ptr)
{
   if (ptr != NULL)
   {
      postOrder(ptr->lchild);
      postOrder(ptr->rchild);
      printf("%c ",ptr -> data);
   }
}
void levelOrder(treeptr ptr)
{

    while(ptr != NULL)
    {
        printf("%c ", ptr->data);

        if(ptr)
        {
            if(ptr ->lchild)
                insertQ(ptr->lchild);
            if(ptr ->rchild)
                insertQ(ptr->rchild);

             ptr = deleteQ();


        }
        else
            break;
    }
}
int main()
{
    treeptr newp = NULL;

    root = (treeptr)malloc(sizeof(tree));
    root -> data = '/';
    root -> lchild = NULL;
    root -> rchild = NULL;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = '*';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> lchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = '+';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> rchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = '+';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> lchild -> lchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = '-';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> lchild -> rchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = 'e';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> rchild -> lchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = 'f';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> rchild -> rchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = 'a';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> lchild -> lchild -> lchild= newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = 'b';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> lchild -> lchild -> rchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = 'c';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> lchild -> rchild -> lchild = newp;

    newp = (treeptr)malloc(sizeof(tree));
    newp -> data = 'd';
    newp -> lchild = NULL;
    newp -> rchild = NULL;
    root -> lchild -> rchild -> rchild = newp;

    preOrder(root);
    printf("\n");
    inOrder(root);
     printf("\n");
    postOrder(root);
     printf("\n");
    levelOrder(root);
     printf("\n");

    return 0;
}
