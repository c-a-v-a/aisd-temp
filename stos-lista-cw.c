#include <stdio.h>
#include<stdlib.h>


typedef struct node
 { 
   int item; 
   struct node *next;
}NODE;
NODE *head=NULL;

void push(int x) {
    NODE* newElement = (NODE*)malloc(sizeof(NODE));
    newElement->item = x;
    newElement->next = head;
    head = newElement;
}

int pop() {
    NODE* helper = head;
    int x = head->item;
    head = head->next;
    free(helper);
    return x;
}

int empty() {
    return head == NULL;
}


int main(){

int i, x, head1;
for(i=0;i<10;i++)
{
   scanf ("%d", &x);
   push(x);
}
printf("czy pusty=%d\n",empty());
for(;!empty();)
printf("+++ze stosu: %d\n", pop());
}
