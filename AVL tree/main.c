#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a>b) ? (a) : (b)

int datalist[] = {20, 30, 15, 35, 32, 8, 10, 14, 3, 9, 5, 50, 60, 70, 46, 49};

typedef struct treeNode *treeptr;
typedef struct treeNode
{
    int data;
    int BF;
    treeptr lchild, rchild;
    int height;

} treeNode;
treeptr root = NULL;


treeNode* rotateLL(treeNode *parent)
{
    treeNode *child = parent->lchild;
    parent->lchild = child->rchild;
    child->rchild = parent;
    return child;
}

treeNode* rotateRR(treeNode *parent)
{
    treeNode *child = parent->rchild;
    parent->rchild = child->lchild;
    child->lchild = parent;
    return child;
}

treeNode* rotateRL(treeNode *parent)
{
    treeNode *child = parent->rchild;
    parent->rchild = rotateLL(child);
    return rotateRR(parent);
}

treeNode* rotateLR(treeNode *parent)
{
    treeNode *child = parent->lchild;
    parent->lchild = rotateRR(child);
    return rotateLL(parent);
}


int height(struct treeNode *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}


int insertBST(int data, treeptr t, treeptr parent);

void insertData(int data, treeptr t, treeptr parent)
{
    printf("insert data %d\n", data);
    insertBST(data, t, parent);
    reCalc(root);
    inorderPrint();
}
int newNode(int data)
{
        root = (treeptr)malloc(sizeof(treeNode));
        root->data = datalist[0];
        root->lchild = NULL;
        root->rchild = NULL;
        root->BF = 0;
        root->height = 1;
        return root;
}
int insertBST(int data, treeptr t, treeptr parent)
{
    if(t == NULL)
        return(newNode(data));
    if(data < t->data)
        t->lchild = insertBST(t->lchild, data, parent);
    else if (data > t->data)
        t->rchild = insertBST(t->rchild, data, parent);

    else
        return t;

    t->height = 1 + max(height(t->lchild), height(t->rchild)));

    if (t->height > 2 && data < t->lchild->data)
        return rotateLL(t);


    if (t->height < 0 && data > t->rchild->data)
        return rotateRR(t);


    if (t->height > 2 && data > t->lchild->data)
    {
        t->lchild =  rotateLL(t->lchild);
        return rotateRL(t);
    }


    if (t->height < 0 && data < t->rchild->data)
    {
        t->rchild = rotateRR(t->rchild);
        return rotateLR(t);
    }
    return t;
}

void reCalc(root)
{


}
void inorderPrint()
{
    if(root != NULL)
    {
        printf("%d BF: %d ", root->data, root->BF);
        inorderPrint(root->lchild);
        inorderPrint(root->rchild);

    }
}

int main()
{
    int numOfData = 16;
    int i, n;

    printf("datalist: ");
    for (i=0; i<numOfData; i++)
        printf("%d ", datalist[i]);
    printf("\n");
    if (root == NULL)
    {
        root = (treeptr)malloc(sizeof(treeNode));
        root->data = datalist[0];
        root->lchild = NULL;
        root->rchild = NULL;
        root->BF = 0;
        root->height = 0;
    }
    for (i=1; i<numOfData; i++)
        insertData(datalist[i], root, NULL);
    inorderPrint();
    return 0;
}
