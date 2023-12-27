#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;

}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;

}

Node* insertNode(Node* root, int data){
    if(root == NULL){
        return createNode(data);

    }
    if(data < root->data){
        root->left = insertNode(root->left, data);
    } else if(data > root->data){
        root->right = insertNode(root->right, data);
    }

    return root;
}

Node* minValueNode(Node* node){
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}


Node* removeNode(Node* root, int data){
    if(root == NULL) {
        return root;
        }

        if(data < root->data){
            root->left = removeNode(root->left, data);

        }else if(data > root->data){
            root->right = removeNode(root->right, data);
        }else {
            if(root->left == NULL){
                Node* temp = root->right;
                free (root);
                return temp;
            }

            Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);

        }
       return root; 

}

//in order
void displayTree(Node* root) {
    if (root != NULL) {
        displayTree(root->left);
        printf("%d ", root->data);
        displayTree(root->right);
    }
}

//preorder
void Preorder(Node* t){
    if(t != NULL){
        printf(" %d",t->data);
        Preorder(t->left);
        Preorder(t->right);
    }
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 10);
    

    printf("Árvore Binária (inorder): ");
    displayTree(root);

    root = removeNode(root, 10);
    printf("\nÁrvore após remover o valor 10: ");
    displayTree(root);

    

    return 0;
}

