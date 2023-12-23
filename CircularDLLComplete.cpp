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
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó no final da lista
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Função para remover um nó da lista
int removeFromList(Node** head, int data) {
    if (*head == NULL) {
        return 0;
    }
    Node *current = *head, *prev = NULL;
    do {
        if (current->data == data) {
            if (prev == NULL) { // Remover o head
                if (current->next == current) { // Único nó na lista
                    *head = NULL;
                } else {
                    prev = *head;
                    while (prev->next != *head) {
                        prev = prev->next;
                    }
                    prev->next = current->next;
                    *head = current->next;
                }
            } else { // Remover um nó que não é o head
                prev->next = current->next;
            }
            free(current);
            return 1;
        }
        prev = current;
        current = current->next;
    } while (current != *head || (prev == NULL && current == *head));
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
    int choice, element, n;

    printf("Digite o número de elementos: ");
    scanf("%d", &n);
    printf("Digite os elementos da lista:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        insertAtEnd(&head, element);
    }

    while (1) {
        printf("\nEscolha a operação:\n");
        printf("1. Inserir Nó\n");
        printf("2. Remover Nó\n");
        printf("3. Exibir Lista\n");
        printf("4. Sair\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite um elemento para inserir: ");
                scanf("%d", &element);
                insertAtEnd(&head, element);
                break;
            case 2:
                printf("Digite um elemento para remover: ");
                scanf("%d", &element);
                if (removeFromList(&head, element)) {
                    printf("Elemento removido.\n");
                } else {
                    printf("Elemento não encontrado.\n");
                }
                break;
            case 3:
                printf("Lista Atual: ");
                Display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}
