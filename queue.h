#include <stdio.h>
#include <stdlib.h>

//structure
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

//wrapper over node
typedef struct queue{
    Node *front;
    Node *rear;
}Queue;

//prototypes
void enqueue(Queue *, int);
int dequeue(Queue *);
int qlength(Queue *);
int isEmpty(Queue *);
void printq(Queue *);


//initialize
void initq(Queue *q){
    q->front = q->rear = NULL;
}


//enqueue
void enqueue(Queue *q, int data){
    //create a new node
    Node *temp = NULL;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if(q->front == NULL){
        //queue is empty
        q->front = q->rear = temp;
    }else{
        q->rear->next = temp;
        q->rear = temp;
    }
}
//dequeue
int dequeue(Queue *q){
    //check if the queue is empty
    if(isEmpty(q)){
        if(q->front == q->rear){
            Node *temp = NULL;
            temp = q->front;
            int data = temp->data;
            q->front = q->rear = NULL;
            free(temp);
            return data;
        }else{
            Node *temp = NULL;
            temp = q->front;
            int data = temp->data;
            q->front = q->front->next;
            free(temp);
            return data;
        }
        
    }else{
       return 0;
    }
}

//num of items
int qlength(Queue *q){
    Node *temp = NULL;
    temp = q->front;
    int len = 0;
    while(temp != NULL){
        temp = temp ->next;
        len += 1;
    }
    return len;
}

//is empty
int isEmpty(Queue *q){
    if(q->front == (Node*)NULL && q->rear == (Node*)NULL){
        return 0;
    }else{
        return 1;
    }
}
//print
void printq(Queue *q){
    Node *temp = NULL;
    temp = q->front;
    if(isEmpty(q)){
        printf("\n ==== QUEUE ====\n");
        while (temp)
        {
            printf("[ %d ]\n", temp->data);
            temp = temp->next;
        }
    }else{
        printf("\nQueue is empty!");
    }
}
