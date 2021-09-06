#include <iostream>
#include <cstdlib>
using namespace std;

int LOOP = 5;

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
        Node *head, *tail, *loop;
        int capacity;
        LinkedList () {
            head = NULL;
            tail = NULL;
            loop = NULL;
            capacity = 0;
        }

        void insert (int data) {
            if (head == NULL) {
                head = new Node(data);
                tail = head;
                capacity++;
            }
            else {
                if (capacity < LOOP) {
                    tail->next = new Node(data);
                    tail = tail->next;
                    capacity++;
                }
                else if (capacity == LOOP){
                    loop = new Node(data);
                    tail->next = loop;
                    tail = loop;
                    capacity++;
                }
                else {
                    tail->next = new Node(data);
                    tail = tail->next;
                    tail->next = loop;
                    capacity++;
                }
            }
        }

        void findCycle () {
            Node *ptr1, *ptr2;
            int l = capacity*2;
            bool isCycle =  false;
            ptr1 = head;
            ptr2 = head;
            while (l--) {
                ptr1 = ptr1->next;
                ptr2 = (ptr2->next)->next;
                if (ptr1 == ptr2) {
                    isCycle = true;
                    break;
                }
            }
            if (isCycle) cout << "cycle at [" << ptr1->data << "]\n";
            else cout << "No cycle found\n";
        }

        void show () {
            Node *temp = head;
            int l = capacity*2;
            while (l--) {
                cout << "[" << temp->data << "] ";
                temp = temp->next;
            }
            cout << "\n";
        }
};


int main () {
    LinkedList ll;
    for (int i=1; i<11; i++) ll.insert(i);
    ll.show();
    ll.findCycle();
    return 0;
}