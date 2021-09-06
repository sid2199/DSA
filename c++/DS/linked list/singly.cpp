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

class LinkedList {
    public:
        Node *head;
        Node *tail;
        LinkedList () {
            head = NULL;
            tail = NULL;
        }

        void insertAtEnd (int data) {
            if (head == NULL) {
                head = new Node(data);
                tail = head;
            }
            else {
                tail->next = new Node(data);
                tail = tail->next;
            }
        }

        void insertAtStarting (int data) {
            if (head == NULL) insertAtEnd(data);
            else {
                Node *temp = new Node(data);
                temp->next = head;
                head = temp;
            }
        }

        void removeFromEnd () {
            Node *temp = head;
            while ((temp->next)->next) temp = temp->next;
            tail = temp;
            temp = temp->next;
            tail->next = NULL;
            free(temp);
        }

        void removeFromStarting() {
            Node *temp = head;
            head = head->next;
            free(temp);
        }

        void show () {
            Node *temp = head;
            while (temp) {
                cout << "[" << temp->data << "] ";
                temp = temp->next;
            }
            cout << "\n";
            free(temp);
        }
};


int main () {
    LinkedList ll;
    for (int i=1; i<11; i++) ll.insertAtEnd(i);
    ll.show();
    ll.removeFromEnd();
    ll.removeFromEnd();
    ll.show();
    ll.insertAtStarting(0);
    ll.show();
    ll.removeFromStarting();
    ll.show();
    return 0;
}