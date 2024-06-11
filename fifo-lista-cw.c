#include <stdio.h>
#include<stdlib.h>

typedef struct node
 { 
   int item; 
   struct node *next;
}NODE;

NODE *head=NULL;
NODE *tail=NULL;

int empty() {
    return head == NULL;
}

void put(int x) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->item = x;
    newNode->next = NULL;

    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
}

int get() {
    if (empty()) {
        printf("puste\n");
        return 1;
    }

    NODE* temp = head;
    int item = temp->item;
    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }
    free(temp);
    return item;
}

int main(){
int i, x;
for(i=0;i<10;i++)
{
   scanf ("%d", &x);
   put(x);
}
printf("czy pusty=%d\n",empty());
for(;!empty();)
   printf("+++z FIFO: %d\n", get());
}
