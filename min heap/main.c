#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_ELEMENT 1000


typedef struct tagNode{
    int data;
}HeapNode;

typedef struct tagHeap{
    HeapNode* Nodes;
    int capacity;
    int usedsize;
}Heap;

Heap* H;

Heap* create(int initsize) //�� ����
{
    Heap* newheap = (Heap*)malloc(sizeof(Heap));
    newheap->capacity = initsize;
    newheap->usedsize = 0;
    newheap->Nodes = (HeapNode*)malloc(sizeof(HeapNode)*newheap->capacity);
    return newheap;
}

void resize()
{
    if(H->usedsize <(H->capacity / 2))
    {
        H->capacity /= 2;
        H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->capacity);

    }
}
void destroy()
{
    free(H->Nodes);
    free(H);
}
int getParent(int index) //�θ� INDEX ���ϱ�
{
    return (int)((index-1) / 2);
}
int getLchild(int index)  //���ڽ� INDEX���ϱ�
{
    return (2*index)+1;
}
int getRchild(int index)  //���ڽ� INDEX���ϱ�
{
    return (2*index)+2;
}

void Swapdata(int index1,int index2) //�����Ͱ� �ٲٱ�
{
    HeapNode T;
    T.data = H->Nodes[index1].data;
    H->Nodes[index1].data = H-> Nodes[index2].data;
    H->Nodes[index2].data = T.data;
}
void Insert(int newdata)   //�� �ֱ�
{

    int currentindex = H->usedsize;
    int parentindex = getParent(currentindex);

    if(H->usedsize == H->capacity)
    {
        H->capacity *= 2;
        H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H ->capacity);

    }
    H->Nodes[currentindex].data = newdata;
    printf("in data : %d \n", newdata);

    while(currentindex > 0 &&
           (H->Nodes[currentindex].data) < (H->Nodes[parentindex].data))  //
    {
        Swapdata(currentindex, parentindex);

        currentindex = parentindex;
        parentindex = getParent(currentindex);
    }
    H->usedsize++;
}
void Delete()
{
    int parentindex = 0;
    int lchildindex = 0;
    int rchildindex = 0;
    printf("out data : %d \n", H->Nodes[0].data);
    H->Nodes[0].data = 0;
    H->usedsize--;
    Swapdata(0,H->usedsize);
    lchildindex = getLchild(0);
    rchildindex = getRchild(0);

    while(1)
    {
        int selchildindex = 0;
        if(lchildindex >= H->usedsize)   //�ڽľ����� break
            break;
        if(rchildindex >= H->usedsize) //���ڽ� ������ ���ڽ����� ����
        {
            selchildindex = lchildindex;
        }
        else
        {
            if(H->Nodes[lchildindex].data > H->Nodes[rchildindex].data)
                selchildindex = rchildindex;
            else
                selchildindex = lchildindex;
        }

        if(H->Nodes[selchildindex].data < H-> Nodes[parentindex].data)
        {
            Swapdata(parentindex,selchildindex);
            parentindex = selchildindex;
        }
        else
            break;

        lchildindex = getLchild(parentindex);
        rchildindex = getRchild(parentindex);
    }
    resize();

}

void printNodes() //MIN HEAP �̱⶧���� ���������� �Ʒ��� ����ϸ� �ڵ����� ������������ ���
{
    for(int i = 0; i< H->usedsize; i++)
    {
        printf("%d ", H->Nodes[i].data);
    }
    printf("\n\n");
}
int main()
{
    H = create(MIN_ELEMENT);
    srand(time(NULL));
    for(int i = 0; i < 20; i++)
    {
        int random = (rand() % 999) + 1;
        Insert(random);
    }
    printNodes();

    for(int j =0; j <5; j++)
    {
        Delete();
        printNodes();
    }
    return 0;
}
