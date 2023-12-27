#include <iostream>
using namespace std;

class Queue {
private:
    int front;
    int rear;
    int size;
    int *Q;

public:
    Queue(int size) {
        front = rear = 0; // Alterado para inicializar front e rear como 0
        this->size = size;
        Q = new int[this->size];
    }

    ~Queue() {
        delete[] Q;
    }

    void enqueue(int x);
    int dequeue();
    void Display();
};

void Queue::enqueue(int x) {
    if ((rear + 1) % size == front) {
        cout << "Queue Full" << endl;
    } else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

int Queue::dequeue() {
    int x = -1;
    if (front == rear) {
        cout << "Queue Empty" << endl;
    } else {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

void Queue::Display() {
    int i = front + 1;
    do {
        cout << Q[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    cout << endl;
}

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Dequeued: " << q.dequeue() << endl;

    q.Display();

    return 0;
}
