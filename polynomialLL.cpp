#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int coeff;
    int exp;
    struct Node *next;
}*poly=NULL;

void create(){
    struct Node *t,*last;
    int num;

    printf("Enter number of terms:");
    scanf("%d",&num);
    printf("Enter terms with coeff and exp:\n");

    for(int i=0;i<num;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d %d",&t->coeff,&t->exp);
        if(poly==NULL){
            poly=t;
            last=poly;
        }
        else{
            last->next=t;
            last=t;
        }
    }
    
}

void Display(){
    struct Node *p=poly;
    while(p!=NULL){
        printf("%dx^%d ",p->coeff,p->exp);
        p=p->next;
    }
}

long Eval(struct Node *poly,int x){
    long sum=0;
    while(poly!=NULL){
        sum+=poly->coeff*pow(x,poly->exp);
        poly=poly->next;
    }
    return sum;
}
int main(){

    create();
    Display();
    printf("\nValue of polynomial with x=3 is %ld",Eval(poly,3));
    printf("\n");



    return 0;
}