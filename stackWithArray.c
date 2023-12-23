#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    int size;
    int *arr;
};

void create(struct Stack *s){
    
    printf("Enter the size of stack\n");
    scanf("%d", &s->size);
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
}

void Display(struct Stack s){
    
    for(int i = 0; i <= s.top; i++){
        printf("%d ", s.arr[i]);
        printf("\n");

    }
}

void push(struct Stack *s, int data){
    
    if(s->top == s->size - 1){
        printf("Stack is full\n");

    }else{
        s->top++;   
        s->arr[s->top] = data;


    }
    }

int pop(struct Stack *s){
    int x = -1;
    if(s->top==-1){
        printf("Stack Underflow\n");
        }
        else{
            x=s->arr[s->top--];
        }
        return x;
    }

int peek(struct Stack s, int index){
int x=-1;
if(s.top-index+1<0){
printf("Invalid Index \n");
x = s.arr[s.top-index+1];

return x;
}
}

int isEmpty(struct Stack s){
    if(s.top==-1){
        return 1;
    }else{
         return 0;
         }
}

int isFull(struct Stack s){
    return s.top==s.size-1;
}

int stackTop(struct Stack s){
    if(!isEmpty(s)){
        return s.arr[s.top];      
    }else {
        return -1;
    }
}


int main(){

struct Stack s;
create(&s);

push(&s, 10);
push(&s,20);
push(&s,30);
push(&s, 40);
push(&s, 50);

printf("%d \n", pop(&s));

Display(s);


    return 0;

}