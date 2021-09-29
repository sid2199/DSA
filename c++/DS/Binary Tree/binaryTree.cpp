#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;
        Node (int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class Tree {
    public:
        Node *head;
        Tree () {
            this->head = NULL;
        }

        void insert (int data) {
            if (!head) head = new Node(data);
            else {
                Node *temp = head;
                while (temp || temp->left || temp->right) {
                    if (temp->data <= data) {
                        if (temp->right) temp = temp->right;
                        else {
                            temp->right = new Node(data);
                            break;
                        }
                    }
                    if (data < temp->data) {
                        if (temp->left) temp = temp->left;
                        else {
                            temp->left = new Node(data);
                            break;
                        }
                    }
                }
            }
        }

        void preOrder (Node *temp) {
            if (temp) {
                cout << "[" << temp->data << "] ";
                preOrder (temp->left);
                preOrder (temp->right);
            }
        }

        void preOrder () {
            Node *temp = head;
            preOrder(temp);
            cout << "\n";
        }

        void inOrder (Node *temp) {
            if (temp) {
                inOrder (temp->left);
                cout << "[" << temp->data << "] ";
                inOrder (temp->right);
            }
        }

        void inOrder () {
            Node *temp = head;
            inOrder(temp);
            cout << "\n";
        }

        void postOrder (Node *temp) {
            if (temp) {
                postOrder (temp->left);
                postOrder (temp->right);
                cout << "[" << temp->data << "] ";
            }
        }

        void postOrder () {
            Node *temp = head;
            postOrder(temp);
            cout << "\n";
        }

        void levelOrder () {
            Node *temp2, *temp = head;
            queue <Node*> que;
            if (temp) que.push(temp);
            while (!que.empty()) {
                temp2 = que.front();
                if (temp2->left) que.push(temp2->left);
                if (temp2->right) que.push(temp2->right);
                cout << "[" << temp2->data << "] ";
                que.pop();
            }
            cout << "\n";
        }

        Node* find (int data, Node *point) {
            if (point) {
                if (point->data == data) return point;
                else if (data < point->data) find(data, point->left);
                else find(data, point->right);
            }
        }

        void remove (int data) {
            Node *found = NULL, *temp = head;
            found = find(data, temp);
            int child;
            if (found->data == data) {
                while (1) {
                    child = 0;
                    if (found->left) child++;
                    if (found->right) child+=2;
                    if (child == 0) {
                        free(found);
                        found = NULL;
                        break;
                    }
                    else if (child == 1) {
                        found->data = found->left->data;
                        free(found->left);
                        found->left = NULL;
                        break;
                    }
                    else if (child == 2) {
                        found->data = found->right->data;
                        free(found->right);
                        found->right = NULL;
                        break;
                    }
                    else if (child == 3) {
                        Node* temp2 = found->left;
                        while (temp2->right) temp2 = temp2->right;
                        found->data = temp2->data;
                        found = temp2;
                    }
                }
            }
            else cout << "data not present in the tree\n";
        }
};

int main () {
    Tree tree;
    int arr[20] = {211,45,23,56,7,5,3,6,43,78,45,678,345,75,45,23,7,3,7,3};
    for (int i=0; i<20; i++) tree.insert(arr[i]);
    // tree.preOrder();
    tree.inOrder();
    // tree.postOrder();
    // tree.levelOrder();
    tree.remove(678);
    tree.remove(78);
    tree.remove(-1);
    tree.inOrder();
    return 0;
}