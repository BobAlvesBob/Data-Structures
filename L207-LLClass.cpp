#include <iostream>

class Node{
    public:
    int data;
    Node *nextNode;
};

class LinkedList{
    private: 
    Node *first;
    public:

    LinkedList(){
        first=NULL;   
    }

    LinkedList(int A[], int n);

    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
    
    };

int main(){


    return 0;
}