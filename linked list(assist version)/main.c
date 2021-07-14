#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE* NODEPTR;
typedef struct _NODE {
    int data;
    NODEPTR next;
}NODE;

NODEPTR Initialize()
{
    NODEPTR head = malloc(sizeof(NODE));
    head->next = NULL;
    return head;
}

void FreeNODE(NODEPTR head)
{
    NODEPTR curr = head->next;
    while (curr != NULL)
    {
        NODEPTR temp = curr->next;
        free(curr);
        curr = temp;
    }
    free(curr);
    free(head);
}

void insert(NODEPTR head, int newdata)
{
    if (head->next != NULL)
    {
        if ((head->next)->data > newdata)
        {
            NODEPTR newnode = malloc(sizeof(NODE));
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
        NODEPTR newnode = malloc(sizeof(NODE));
        newnode->next = head->next;
        newnode->data = newdata;
        head->next = newnode;
        return;
    }
}

void delete(NODEPTR head, int target)
{
    if (head->next == NULL)
    {
        printf("list is empty\n");
        return;
    }
    else
    {
        printf("%d번째 node 삭제\n", target);
        NODEPTR curr = head;
        for (int i = 0; i < target - 1; i++)
            curr = curr->next;
        NODEPTR temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }
}

void PrintNODE(NODEPTR head)
{
    if (head->next == NULL)
    {
        printf("list is empty\n");
        return;
    }
    else
    {
        int a = 1;
        NODEPTR curr = head->next;
        while (curr != NULL)
        {
            printf("%d번째 linked list : %d\n", a, curr->data);
            curr = curr->next;
            a++;
        }
        printf("\n");
    }
}

int main()
{
    NODEPTR head = Initialize();

    insert(head, 5);
    insert(head, 1);
    insert(head, 8);
    insert(head, 2);
    insert(head, 7);
    insert(head, 3);

    printf("insert 후의 list\n");
    PrintNODE(head);

    delete(head, 8);
    PrintNODE(head);

    delete(head, 5);
    PrintNODE(head);

    FreeNODE(head);

    return 0;
}
