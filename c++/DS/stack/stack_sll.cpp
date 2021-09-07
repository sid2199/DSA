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

class Stack {
    public:
        Node *head;
        Stack () {
            head = NULL;
        }

        void push (int data) {
            if (head == NULL) head = new Node(data);
            else {
                Node *temp = new Node(data);
                temp->next = head;
                head = temp;
            }
        }

        void pop () {
            cout << "POP: " << head -> data <<"\n";
            Node *temp = head;
            head = head->next;
            free(temp);
        }

        void peek () {
            if (head != NULL) {
                cout << "TOP: " << head->data << "\n";
            }
        }

        void show () {
            Node *temp = head;
            cout << "stack: ";
            while (temp) {
                cout << "[" << temp->data << "] ";
                temp = temp->next;
            }
            cout << "\n";
            free(temp);
        }
};

int main () {
    Stack stack;
    for (int i=1; i<11; i++) stack.push(i);
    stack.show();
    stack.pop();
    stack.peek();
    stack.pop();
    stack.show();
    return 0;
}