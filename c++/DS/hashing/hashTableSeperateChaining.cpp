#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10

class Node {
    public:
        string name;
        int age;
        Node *next;
        Node (string name, int age) {
            this->name = name;
            this->age = age;
            this->next = NULL;
        }
};

class HashTable {
    public:
        Node* table[SIZE];
        HashTable () {
            this->table[SIZE];
            for (int i=0; i<SIZE; i++) this->table[i] = NULL;
        }

        int hashFunction (string name, int age) {
            int hash = (name.length() + age) % SIZE;
            return hash;
        }

        void insert (string name, int age) {
            int ind = hashFunction(name, age);
            if (!this->table[ind]) this->table[ind] = new Node(name, age);
            else {
                Node *temp = this->table[ind];
                while (temp) {
                    if (temp->name != name || temp->age != age) {
                        if (temp->next) temp = temp->next;
                        else {
                            temp->next = new Node(name, age);
                            break;
                        }
                    }
                    else {
                        cout << "Value {"<< name << " and " << age << "} already in the Table\n";
                        break;
                    }
                }
            }
        }

        void show () {
            for (int i=0; i<SIZE; i++) {
                cout << i << ": ";
                if (this->table[i]) {
                    Node *temp = this->table[i];
                    while (temp) {
                        cout << "[" << temp->name << ", " << temp->age << "] ";
                        temp = temp->next;
                    }
                }
                cout << "\n";
            }
        }
};


int main () {
    string names[] = {"sam", "sid", "sub", "raj" ,"keed" , "chitu" ,"shani" , "pattu", "choor", "minion", "fex", "chi", "tan", "dex", "chitu"};
    int ages[] = {23, 45, 12, 12, 12, 34, 76, 89, 90, 56, 76, 45, 34, 96, 34};
    HashTable hashTable;
    for (int i=0; i<15; i++) hashTable.insert(names[i], ages[i]);
    hashTable.show();
    return 0;
}