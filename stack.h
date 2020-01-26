#include <stdio.h>
#include <stdlib.h>  //malloc

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct stack{
    Node *top;
}Stack;

//prototypes
void push(Stack *,int);
int pop(Stack *);
int stacktop(Stack *);
int stacksize(Stack *);
int isEmpty(Stack *);
void printstk(Stack *);
void init(Stack *);

//init
void init(Stack *s)
{
    s->top = NULL;
}

//push
void push(Stack *s, int data)
{
    //create a new node
    Node *temp = NULL;
    temp = (Node*)malloc(sizeof(Node*));
    temp->next = NULL;
    temp->data = data;
    if(s->top == NULL){
        //stack empty
        s->top = temp;
    }else{
       temp->next = s->top;
       s->top = temp;
    }
}
//pop
int pop(Stack *s){
    Node *temp = NULL;
    temp = s->top;
    int data = temp->data;

    if(!isEmpty(s)){
        return -1;
    }else{
        s->top = s->top->next;
        free(temp);
        return data;
    }
}
//stacktop
int stacktop(Stack *s){
    return s->top->data;
}

//stacksize
int stacksize(Stack *s){
    Node *temp = NULL;
    temp = s->top;
    int total = 0;
    while(temp){
        total += 1;
        temp = temp->next;
    }
    return total;
}

//is empty
int isEmpty(Stack *s){
    if(s->top == NULL){
        return 0;
    }else{
        return 1;
    }
}

//print stack
void printstk(Stack *s){
    Node *temp = NULL;
    temp = s->top;
    printf("\n ==== STACK ====\n");
    if(!isEmpty(s)){
        printf("\nStack empty!\n");
    }else{
        while(temp){
            printf("[ %d ]\n",temp->data);
            temp = temp->next;
        }
    }
}