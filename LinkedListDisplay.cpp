#include <iostream>
#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
}*first=NULL;


void create(int A[], int n){

int i;
struct Node *t, *last;
first = (struct Node *)malloc(sizeof(struct Node));
first -> data  = A[0];
first -> next = NULL;
last = first;

for(i=1; i<n; i++){

    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next = NULL;
    last -> next = t;
    last = t;

}

}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d \n", p->data);
        p=p->next;
    }

}

void DisplayInverse(struct Node *p){
    if(p!=NULL){
        DisplayInverse(p->next);
        printf("%d\n ", p->data);
    }
}

// int count(struct Node*p){
//     if(p==0){
//         return 0;
//         }else{
//             return count(p->next+1);
//         }   
        
// }
int count(struct Node *p){
    int l=0;
    while(p){
        l++;
        p=p->next;
    }
    return l;
}

int Add(struct Node*p){
    int sum = 0;
    while (p){
        sum+=p->data;
        p=p->next;
        
    }
    return sum;
}

int RSum(struct Node *p){
    if(p==NULL){
        return 0;
    }else{
        return RSum(p->next)+p->data;
    }
}

int Rcount(struct Node *p){ //Recursive Count
    if(p!=NULL){
        return Rcount(p->next)+1;
        }
        else{
            return 0;
        }
    }

int Max(struct Node *p){
    int max = INT32_MIN;

    while(p){
        if(p->data>max){
            max=p->data;
           
        }
         p=p->next;
        
    }
    return max;
}

int RMax(struct Node *p){
    int x=0;
    if(p==0){
        return INT32_MIN;}
else{
    x=RMax(p->next);
    if(x>p->data){
        return x;
    }else{
        return p->data;
    }

}


}

struct Node * LSearch(struct Node *p, int key){
    while(p !=NULL){
        if(key==p->data){
            return p;
           
        }
        p=p->next; 
    }
    return  NULL;
}

struct Node * RSearch(struct Node *p, int key){
    if(p==NULL){
        return NULL;
    }
    if(key==p->data){
        return p;
        
    }
    RSearch(p->next, key );
}

void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;

    if(index < 0 || index > count(p)){
        return;
    }
    t=(struct Node *)malloc(sizeof(struct Node));
    
    t->data=x;

    if(index==0){
        t->next  = first;
        first = t;
    }
    else{
        for(i=0; i<index-1; i++){
            p=p->next;
        }
            t->next=p->next;
            p->next=t;

        } 

}

void SortedInsert(struct Node *p, int x){

struct Node *t, *q = NULL;

t = (struct Node*)malloc(sizeof(struct Node));
t->data = x;
t->next = NULL;

if(first == NULL){
    first = t;
}else{
    while(p && p->data<x){
        q=p;
        p=p->next;
    }
    if(p==first){
        t->next=first;
        first = t;

    }else{
        t->next = q->next;
        q->next = t;
    }
}

}

int Delete (struct Node *p, int index){
    struct Node *q=NULL;
    int x=-1,i;
    if(index < 1 || index > count(p)){
        return -1;
    }
    if(index==1){
        q = first;
        x=first->data;
        first=first->next;
        free (q);
        return x;

    }
    else{
        for (i=0; i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        return x;

    }
    


}

int isSorted(struct Node *p){
    int x= INT32_MIN;

    while(p!=NULL){
        if(p->data < x){
            return 0;
        }
            x = p->data;
            p = p->next;
        
       
    }
     return 1;
}

void RemoveDuplicate(struct Node *p){
  struct Node *q=p->next;
  while(q!=NULL){

    if(p->data != q->data){
        p=q;
        q=q->next;
    }else{
        p->next = q->next;
        free(q);
        q=p->next;
    }

  }  
}

void Reverse1(struct Node *p){
    int i=0;
    

    struct Node *q = p;//Help traverse 
    int *A = (int *)malloc(sizeof(int)*count(p));

    while(q!=NULL){
        A[i++]=q->data;
        q=q->next;
        
            }
         q=p;
        i--;// Decrementa para apontar para o último elemento do array
    // Copia os dados de volta para a lista na ordem inversa
        while(q!=NULL){

            q->data=A[i--];
            q=q->next;
            

        }
        free(A);

}

void Reverse2(struct Node *p){
    //3 pointers!!!1
    struct Node *q = NULL, *r = NULL;

    while(p != NULL){
       r = q;
       q = p;
       p = p->next;
       q->next=r;
    }


}

void Concat(struct Node *p, struct Node *q) {
    if (p == NULL) {
        // If the first list is empty, the result is the second list
        first = q;
    } else {
        // Find the last node of the first list
        while (p->next != NULL) {
            p = p->next;
        }
        // Link the last node of the first list to the first node of the second list
        p->next = q;
    }
}

struct Node *Merge(struct Node *first, struct Node *second) {
    struct Node *third, *last;
    if (first == NULL) return second;
    if (second == NULL) return first;

    // Inicializa third e last
    if (first->data < second->data) {
        third = last = first;
        first = first->next;
        last->next = NULL;
    } else {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }

    // Percorre as duas listas
    while (first != NULL && second != NULL) {
        if (first->data < second->data) {
            last->next = first;
            last = first;
            first = first->next;
        } else {
            last->next = second;
            last = second;
            second = second->next;
        }
        last->next = NULL;
    }

    // Anexa a lista restante
    if (first != NULL) last->next = first;
    if (second != NULL) last->next = second;

    return third;
}

int isLoop(struct Node *f) {
    struct Node *p, *q;
    p = q = f;

    do {
        p = p->next;        // Move p por um nó
        q = q->next;        // Move q por um nó
        if (q != NULL) q = q->next;  // Move q por um segundo nó, se possível

        if (p == NULL || q == NULL) return 0;  // Sem loop, pois chegou ao fim da lista

    } while (p != q);

    return 1;  // Loop detectado, pois p e q se encontraram
}




int main(){

    struct Node *temp;

int A[]={3,5,7,10,15, 22, 19, 81, 77, 1, 99, 12, 314, 420, 69, 666, 88, 777};
//int A[]={3,5,7};


 create(A, 19);

 Display(first);

 printf("\n\n");

 SortedInsert(first, 2);

 Display(first);

 Delete(first, 2);

 std::cout<<std::endl;

 Display(first);

 printf("%d\n", isSorted(first));

 Reverse1(first);

 Display(first);

// Insert(first,0,10);
// Display(first);

// temp = RSearch(first, 666);
// if(temp){
//     printf("Key was Found: %d\n", temp->data);
// } else{ printf("Key not found\n");}

// printf("Length is %d\n", Rcount(first));

// //Display(first);
// DisplayInverse(first);

// std::cout<<"Sum of all elements:"<<RSum(first)<<std::endl;

// printf("Max is %d\n", RMax(first));

    return 0;
}