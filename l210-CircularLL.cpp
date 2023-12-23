#include <iostream>

struct Node{

    int data;
    struct Node *next;

}*Head;

void create(int A[], int n){
    int i; 
    struct Node *t, *last;
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next=Head;

for(i=1; i<n; i++){
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next = last->next;
    last -> next = t;
    last = t;
}}

void Display(struct Node *h){
    do {
        printf("%d", h->data);
        h=h->next;
    }while( h != Head);
    
}

int main(){

int A[]={2,3,4,5,6,7};

create(A,5);



    return 0;

}