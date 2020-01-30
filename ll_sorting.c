#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

//wrapper over the node
typedef struct LL
{
    Node *head;
    Node *rear;
}LL;

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

//swap the address of the two nodes and not just the value
void swapnode(LL *l,Node *before, Node *addr1, Node *addr2)
{
    Node *temp = NULL;
    temp = addr2;
    addr1->next = addr2->next;
    if(before != NULL){
        addr2->next = addr1;
        before->next = addr2;
    }else{
        addr2->next = addr1;
        l->head = addr2;
    }
    
}

//length of the linke list
int len(LL *l){
    int total = 0;
    Node *temp = NULL;
    temp = l->head;
    while(temp != NULL){
        total +=1;
        temp = temp->next;
    }
    return total;
}

//sort the linked list by swapping the data of nodes and not the actual nodes
void sort(LL *l){
    Node *temp = NULL,*temp1 = NULL,*temp2=NULL;
    for(temp1 = l->head; temp1!=NULL; temp1 = temp1->next){
        for(temp2 = temp1->next; temp2!=NULL;){
            if(temp2->data < temp1->data){
                int a = temp1->data;
                temp1->data = temp2->data;
                temp2->data = a;
            } 
            temp2 = temp2->next;
        }
    }
}

int main(int argc, char *argv[])
{
    return 0;
}