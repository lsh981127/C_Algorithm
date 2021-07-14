#include <stdio.h>
#include <stdlib.h>

typedef struct _node* nodeptr;
typedef struct _node{
    int data;
    nodeptr next;
}node;



void insert(nodeptr head, int newdata)
    if (head->next != NULL)
    {
        if ((head->next)->data > newdata)
        {
            nodeptr newp = malloc(sizeof(node));
            newnode->next = head->next;
            newnode->data = newdata;
            head->next = newnode;
            return;
        }
        else
        {
            insert(head->next, newdata);
            return;
        }
    }
    else
    {
        nodeptr newnode = malloc(sizeof(node)));
        newnode->next = head->next;
        newnode->data = newdata;
        head->next = newnode;
        return;
    }
}
void delete()
{

}
void print()
{

}
int main()
{
    nodeptr head;
    head = malloc(sizeof(struct node));
    head == NULL;
    int x;
    for(int i = 0; i < 5, i++){
        printf("추가하고 싶은 노드의 데이터값을 입력하시오.\n");
        scanf("%d", &x);
        insert(head, x);
    }

}

    return 0;
}
