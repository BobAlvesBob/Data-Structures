#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;

}*front = NULL, *rear = NULL;

void enqueue(int x){
  struct Node *t;
  t = (struct Node* )malloc(sizeof(struct Node));  
  if(t == NULL){
    printf("Queue is full\n");
  }
else{
    t-> data = x;
    t->next = NULL;
    if(front == NULL){
        front=rear=t;
    }
    else{
        rear->next = t;
        rear = t;
    }
}
  }

int dequeue(){
    int x = -1;
    struct Node* t;
    if(front==NULL){
        printf("Queue is empty");

    }
    else{
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;

}

void Display(){
    struct Node *p = front;
    while(p){
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("\n");
}


int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    printf("Fila após enqueues: \n");
    Display();

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    printf("Fila após dequeues: \n");
    Display();

    return 0;
}
