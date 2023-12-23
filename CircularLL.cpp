#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode; // Em uma lista circular, inicialmente o nó aponta para si mesmo
    return newNode;
}

// Função para inserir um nó em uma lista ligada circular
void insertNode(Node **head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
    }
}

// Função para remover um nó de uma lista ligada circular
int removeNode(Node **head, int value) {
    if (*head == NULL) {
        return 0;
    }

    Node *current = *head, *prev = NULL;
    do {
        if (current->data == value) {
            if (prev == NULL) { // Remover o head
                // Encontrar o nó anterior ao head
                Node *last = *head;
                while (last->next != *head) {
                    last = last->next;
                }
                if (last == *head) { // Único nó na lista
                    *head = NULL;
                } else {
                    last->next = (*head)->next;
                    *head = (*head)->next;
                }
            } else { // Remover um nó que não é o head
                prev->next = current->next;
            }
            free(current);
            return 1;
        }
        prev = current;
        current = current->next;
    } while (current != *head);
    
    return 0;
}

// Função para exibir a lista
void Display(Node *head) {
    if (head == NULL) return;
    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node *head = NULL;
    int n, data;

    printf("Digite o número de elementos na lista: ");
    scanf("%d", &n);

    printf("Digite %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("Lista Circular: ");
    Display(head);

    // Exemplo de remoção
    printf("\nDigite um elemento para remover: ");
    scanf("%d", &data);
    if (removeNode(&head, data)) {
        printf("Elemento removido com sucesso.\n");
        printf("Lista Circular após remoção: ");
        Display(head);
    } else {
        printf("Elemento não encontrado.\n");
    }

    return 0;
}
