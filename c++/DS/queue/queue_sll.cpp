#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node (int data) {
            this->data = data;
            this->next = NULL;
        }
};

class Queue {
    public:
        Node *front, *back;
        Queue () {
            front = NULL;
            back = NULL;
        }

        void enqueue (int data) {
            if (front == NULL) {
                front = new Node(data);
                back = front;
            }
            else {
                back->next = new Node(data);
                back = back->next;
            }
        }

        void dequeue () {
            if (front) {
                Node *temp = front;
                front = front->next;
                cout << "Dequeue: [" << temp->data << "]\n";
                free(temp);
            }
            else cout << "No one in the queue\n";
        }

        void show () {
            Node *temp = front;
            while (temp) {
                cout << "[" << temp->data << "] ";
                temp = temp->next;
            }
            cout << "\n";
        }
};

int main () {
    Queue queue;
    for (int i=1; i<11; i++) queue.enqueue(i);
    queue.show();
    for (int i=0; i<13; i++) queue.dequeue();
    queue.enqueue(1);
    queue.enqueue(2);
    queue.show();
    return 0;
}