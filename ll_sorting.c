#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct LL
{
    Node *head;
    Node *rear;
} LL;

//init ll
void initll(LL *l)
{
    l->head = l->rear = NULL;
}

//append at the end of the ll
void append(LL *l, int data)
{
    Node *temp = NULL;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (l->head == NULL)
    {
        l->head = l->rear = temp;
    }
    else
    {
        l->rear->next = temp;
        l->rear = temp;
    }
}

//make the ll from an array
void makell(int *arr, int len, LL *l)
{
    for (int i = 0; i < len; i++)
    {
        append(l, arr[i]);
    }
}

void printll(LL *l)
{
    Node *temp = l->head;
    while (temp != NULL)
    {
        printf("\n[ %d ]", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void swapnode(Node *before, Node *addr1, Node *addr2)
{
    Node *temp = NULL;
    temp = addr2;
    addr1->next = addr2->next;
    before->next = addr2;
    addr2->next = addr1;
}

int main(void)
{
    int ll[] = {1, 4, 6, 7, 9, 3, 6};
    LL l;
    initll(&l);
    makell(ll, 7, &l);
    printll(&l);
    Node *temp = NULL;
    temp = l.head;
    Node *before = NULL;
    while (temp->data != 9)
    {
        before = temp;
        temp = temp->next;
    }
    swapnode(before, temp, temp->next);
    printll(&l);
}