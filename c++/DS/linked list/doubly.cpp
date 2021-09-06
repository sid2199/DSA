#include <iostream>
#include <cstdlib>
using namespace std;


class Node {
    public:
        int data;
        Node *next, *prev;
        Node (int data) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

class LLinkedList {
    public:
        Node *head, *tail;
        LLinkedList () {
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
                (tail->next)->prev = tail;
                tail = tail->next;
            }
        }

        void removeFromEnd () {
            if (tail) {
                Node *temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                free(temp);
            }
        }

        void insertAtStarting (int data) {
            if (head == NULL) insertAtEnd(data);
            else {
                Node *temp = new Node(data);
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        }

        void removeAtStarting () {
            if (head) {
                Node *temp = head;
                head = head->next;
                head->prev = NULL;
                free(temp);
            }
        }

        void show (int order) {
            if (order > 0) {
                Node *temp = head;
                while (temp) {
                    cout << "[" << temp->data << "] ";
                    temp = temp->next;
                }
                free(temp);
            }
            else {
                Node *temp = tail;
                while (temp) {
                    cout << "[" << temp->data <<"] ";
                    temp = temp->prev;
                }
                free(temp);
            }
            cout << "\n";
        }
};


int main () {
    LLinkedList ll;
    for (int i=1; i<11; i++) ll.insertAtEnd(i);
    ll.show(1);
    ll.show(0);
    ll.removeFromEnd();
    ll.removeFromEnd();
    ll.insertAtStarting(0);
    ll.insertAtStarting(-1);
    ll.show(1);
    ll.removeAtStarting();
    ll.show(1);
    ll.show(0);
    return 0;
}