#include <iostream>
#include <cstdlib>
using namespace std;

class PriorityQueue {
    public:
        int *PQ;
        int size, n;
        PriorityQueue () {
            size = -1;
            n = 1;
            PQ = (int*) malloc (sizeof(int)*(n-1));
        }

        void heapifyUp (int from) {
            int parent, ind = from;
            while (ind > 0) {
                if (ind%2==0) parent = ((ind-1)/2);
                else parent = ind/2;
                if (PQ[parent] < PQ[ind]) {
                    int temp = PQ[ind];
                    PQ[ind] = PQ[parent];
                    PQ[parent] = temp;
                }
                ind = parent;
            }
        }

        void heapifyDown (int from) {
            int leftChild, rightChild, ind = from;
            while (ind < size) {
                if (((ind*2)+2) <= size) {
                    rightChild = (ind*2)+2;
                    leftChild = (ind*2)+1;
                    int max = PQ[leftChild]>PQ[rightChild]?leftChild:rightChild;
                    if (PQ[ind] < PQ[max]) {
                        int temp = PQ[ind];
                        PQ[ind] = PQ[max];
                        PQ[max] = temp;
                        ind = max;
                    }
                    else break;
                }
                else if (((ind*2)+1) <= size) {
                    leftChild = (ind*2)+1;
                    if (PQ[ind] < PQ[leftChild]) {
                        int temp = PQ[ind];
                        PQ[ind] = PQ[leftChild];
                        PQ[leftChild] = temp;
                        ind = leftChild;
                    }
                    else break;
                }
                else break;
            }
        }

        void insert (int data) {
            if (size >= (n-1)) PQ = (int*) realloc (PQ, sizeof(int)*((n*=2)-1));
            PQ[++size] = data;
            heapifyUp(size);
        }

        void extractMax () {
            if (size > -1) {
                cout << "Max: [" << PQ[0] << "]\n";
                PQ[0] = PQ[--size];
                heapifyDown(0);
                if (size < (n/2)) PQ = (int*) realloc (PQ, sizeof(int)*(n/=2));
            }
            else cout << "Nothing in the Priority Queue remaining\n";
        }
        
        void remove (int data) {
            int found = NULL;
            for (int i=0; i<size; i++) if (PQ[i] == data) found = i;
            if (found) {
                cout << "Removed: [" << PQ[found] << "]\n";
                PQ[found] = PQ[--size];
                heapifyUp(found);
                heapifyDown(found);
            }
        }

        void show () {
            if (size > -1) {
                for (int i=0; i<size; i++) cout << "[" << PQ[i] << "] ";
                cout << "\n";
            }
            else cout << "Priority Queue Empty\n";
        }
};

int main () {
    int prior[] = {0,23,10,1,2,7,3,65,23,4,4,4,3,56,12,12,4};
    PriorityQueue pq;
    for (auto i: prior) pq.insert(i);
    pq.show();
    pq.extractMax();
    pq.show();
    pq.extractMax();
    pq.show();
    pq.remove(12);
    pq.show();
    pq.remove(4);
    pq.show();
    pq.remove(23);
    pq.show();
    return 0;
}