#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

class Node {
    public:
        int data, height, bf;
        Node *left, *right;
        Node (int data) {
            this->data = data;
            this->height = 1;
            this->bf = 0;
            this->left = NULL;
            this->right = NULL;
        }
};

class AVL {
    public:
        Node *root;
        AVL () {
            this->root = NULL;
        }

        void check () {                                                                                                 // for debugging purpose
            queue <Node*> tree;
            tree.push(this->root);
            cout << "ROOT -> ";
            while (!tree.empty()) {
                Node *front = tree.front();
                if (front == NULL) cout << "[NULL] ";
                else {
                    if (front->left) tree.push(front->left);
                    else tree.push(NULL);
                    if (front->right) tree.push(front->right);
                    else tree.push(NULL);
                    cout << "[" << front->data << ", " << front->bf << ", " << front->height << "] ";                   // print current node data, balance factor and height
                }
                tree.pop();
            }
            cout << "\n";
        }

        void insert (int data) {
            Node *node = this->root;
            if (!node) this->root = new Node(data);
            else {
                insertR(data, node);
            }
        }

        void insertR (int data, Node *node) {
            if (data < node->data) {
                if (node->left) insertR(data, node->left);
                else node->left = new Node(data);
            }
            else if (node->data < data) {
                if (node->right) insertR(data, node->right);
                else node->right = new Node(data);
            }
            else {
                cout << "Duplicate value are not allowed in the tree\n";
            }
            update(node);
            balance(node);
        }

        void update (Node *node) {
            int leftHeight = node->left?node->left->height+1:1;
            int rightHeight = node->right?node->right->height+1:1;
            node->height = max(leftHeight, rightHeight);
            node->bf = leftHeight - rightHeight;
        }

        int max (int x, int y) {
            return x>y?x:y;
        }

        void balance (Node *node) {
            if (node->bf == -2) {
                if (node->right->bf == -1) rightRightCase(node);
                else rightLeftCase(node);
            }
            else if (node->bf == 2) {
                if (node->left->bf == 1) leftLeftCase(node);
                else leftRightCase(node);
            }
        }

        void updateNodes(Node *node) {                                                                          // update the rotated node with new height and balance factor
            update(node->left);
            update(node->right);
            update(node);
        }

        void rightRightCase (Node *node) {
            cout << "--------------------Applying RR Rotation--------------------\n";
            int newParentData = node->right->data;
            Node *newParentLeft = node->right->left;
            Node *newParentRight = node->right->right;
            Node *oldParentLeft = node->left;
            Node *newLeft = new Node(node->data);
            newLeft->left = node->left;
            newLeft->right = newParentLeft;
            node->left = newLeft;
            node->data = newParentData;
            node->right = newParentRight;
            updateNodes(node);
        }

        void rightLeftCase (Node *node) {
            cout << "--------------------Applying RL Rotation on "<< node->data << "--------------------\n";
            Node *newLeft = new Node(node->data);
            int newParentDate = node->right->left->data;
            Node *newParentLeft = node->right->left->left;
            Node *newParentRight = node->right->left->right;
            node->data = newParentDate;
            Node *oldLeft = node->left;
            node->left = newLeft;
            newLeft->left = oldLeft;
            newLeft->right = newParentLeft;
            node->right->left = node->right->left->right;
            updateNodes(node);
        }

        void leftLeftCase (Node *node) {
            cout << "--------------------Applying LL Rotation--------------------\n";
            int newParentData = node->left->data;
            Node *newParentLeft = node->left->left;
            Node *newParentRight = node->left->right;
            Node *newRight = new Node(node->data);
            newRight->right = node->right;
            newRight->left = newParentRight;
            node->data = newParentData;
            node->left = newParentLeft;
            node->right = newRight;
            updateNodes(node);
        }

        void leftRightCase (Node *node) {
            cout << "--------------------Applying LR Rotation--------------------\n";
            int newParentData = node->left->right->data;
            Node *newParentLeft = node->left->right->left;
            Node *newParentRight = node->left->right->right;
            Node *newRight = new Node(node->data);
            newRight->left = newParentRight;
            newRight->right = node->right;
            node->data = newParentData;
            node->right = newRight;
            node->left->right = newParentLeft;
            updateNodes(node);
        }

        void showR (Node *node) {
            if (node) {
                showR(node->left);
                cout << "[" << node->data << "] ";
                showR(node->right);
            }
        }

        void show () {
            Node *node = this->root;
            cout << "ROOT -> ";
            showR (node);
            cout << "\n";
        }

        void lOT () {
            queue <Node*> tree;
            tree.push(this->root);
            cout << "ROOT -> ";
            while (!tree.empty()) {
                Node *front = tree.front();
                if (front->left) tree.push(front->left);
                if (front->right) tree.push(front->right);
                cout << "[" << front->data << "] ";
                tree.pop();
            }
            cout << "\n";
        }

        void showMatrix () {
            queue <Node*> tree;
            tree.push(this->root);
            cout << "--------------------Tree Matric-------------------- \n";
            int cur=0, lim=1;
            while (!tree.empty()) {
                Node *front = tree.front();
                if (front == NULL) cout << "[ ] ";
                else {
                    if (front->left) tree.push(front->left);
                    else tree.push(NULL);
                    if (front->right) tree.push(front->right);
                    else tree.push(NULL);
                    cout << "[" << front->data << "] ";
                }
                if (++cur >= lim) {
                    lim+=lim;
                    cur = 0;
                    cout << "\n";
                }
                tree.pop();
            }
            cout << "\n";
        }

        void remove (int data ) {
            removeR(this->root, data);
        }

        void removeR (Node *node, int data) {
            if (node->data < data) removeR(node->right, data);
            else if (data > node->data) removeR(node->left, data);
            else if (node->data == data) {
                if (node->left && node->right) {
                    if (node->right->left) node->data = removeAndUpdate(node->right);
                    *node = *node->right;
                }
                else if (node->left || node->right) {
                    if (node->left) *node = *node->left;
                    else *node = *node->right;
                }
                else {
                    node = NULL;
                    free(node);
                }
            }
            else cout << data << " not in the tree\n";
            update(node);
        }

        int removeAndUpdate (Node *node) {
            int data;
            if (node->left->left) return removeAndUpdate(node->left);
            else {
                int data = node->left->data;
                free(node->left);
                node->left = NULL;
            }
            update(node);
            return data;
        }
};

int main () {
    AVL tree;
    // int arr[] = {1,5,3,6,4,3,4,6,9,4,3,6,8,23,34,8,45,345,8,78,3,5,78,234};              // mix
    // int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};                    // RR
    // int arr[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};                    // LL
    int arr[] = {40,30,50,20,35,45,60,41,46,70,42};                                      // mix
    for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++) tree.insert(arr[i]);
    // tree.show();
    tree.lOT();
    tree.showMatrix();
    tree.remove(60);
    tree.remove(42);
    tree.showMatrix();
    tree.remove(45);
    tree.showMatrix();
    // tree.check();
    return 0;
}