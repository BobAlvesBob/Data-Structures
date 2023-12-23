#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node **top, int x) {
    struct Node *t = (struct Node*) malloc(sizeof(struct Node));
    if (t == NULL) {
        printf("Stack is full\n");
    } else {
        t->data = x;
        t->next = *top;
        *top = t;
    }
}

int pop(struct Node **top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    } else {
        struct Node *t = *top;
        int x = t->data;
        *top = (*top)->next;
        free(t);
        return x;
    }
}

void Display(struct Node *top){
    struct Node *p = top;
    p=top;
    while(p != NULL){
        printf(" %d", p->data);
        p=p->next;
    }
}

int main() {
    struct Node *top = NULL;
    
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printf("Popped: %d\n", pop(&top));
    printf("Popped: %d\n", pop(&top));

    return 0;
}
