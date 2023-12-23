#include <iostream>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;

}*first=NULL;

void create(int A[], int n){
    struct Node *t, *last;
    int i;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next=NULL;
    last = first;
    for(i=1; i<n; i++){
        t= (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev=last;
        last->next=t;
        last=t;

    }

}

void Display(struct Node *p){
    while(p){
        printf("%d\n ",p->data);
        p=p->next;

    }
    printf("\n");
}

int Length(struct Node *p){
int len=0;

while(p){
    len++;
    p=p->next;

}
}

void Insert(struct Node *p, int index, int x){

    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index < 0 || index > Length(p)){
        return;
    }
    if(index==0){
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        for(int i=0; i<index-1; i++){
            p=p->next;
        }
        t->next=p->next;
        p->next->prev=t;
        p->next=t;
        t->prev=p;
    }
}

void Delete(struct Node *p, int index){

    if(index < 0 || index > Length(p)){
        return;
    }
    if(index==1){
        first=first->next;
        first->prev=NULL;
        free(p);
    }
    else{
        for(int i=0; i<index-1; i++){
            p=p->next;
        }
        p->next=p->next->next;
        p->next->prev=p;
        free(p->next);
    }
}

void ReverseDoubleLinkedList(struct Node *p){
    
struct Node *temp;

while(p!=NULL){
    temp=p->next;
    p->next=p->prev;
    p->prev=temp;
    p=p->prev;
    if(p!=NULL && p->next==NULL){
        first=p;
    }
}
}

int main(){
    
    int A[]={10,20,30,40,50};
    create(A,5);

    printf("\n  Length is: %d\n",Length(first));

    Display(first);
    ReverseDoubleLinkedList(first);
    Display(first);

    return 0;


}