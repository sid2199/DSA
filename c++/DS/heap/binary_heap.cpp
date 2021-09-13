#include <iostream>
#include <cstdlib>
using namespace std;

class Heap {
    public:
        int *heap;
        int size, n;
        Heap () {
            n = 1;
            size = -1;
            heap = (int*) malloc (sizeof(int)*(n-1));
        }

        void heapifyUp () {
            int parent, ind = size;
            while (ind > 0) {
                if (ind%2 == 0) parent = (ind-1)/2;
                else parent = ind/2;
                if (heap[ind] > heap[parent]) {
                    int temp = heap[ind];
                    heap[ind] = heap[parent];
                    heap[parent] = temp;
                }
                ind = parent;
            }
        }

        void heapifyDown () {
            int leftChild, rightChild, ind = 0;
            while (ind < size) {
                if (((ind*2)+2) <= size) {
                    rightChild = (ind*2)+2;
                    leftChild = (ind*2)+1;
                    int max = heap[leftChild]>heap[rightChild]?leftChild:rightChild;
                    if (heap[ind] < heap[max]) {
                        int temp = heap[ind];
                        heap[ind] = heap[max];
                        heap[max] = temp;
                        ind = max;
                    }
                    else break;
                }
                else if (((ind*2)+1) <= size) {
                    leftChild = (ind*2)+1;
                    if (heap[ind] < heap[leftChild]) {
                        int temp = heap[ind];
                        heap[ind] = heap[leftChild];
                        heap[leftChild] = temp;
                        ind = leftChild;
                    }
                    else break;
                }
                else break;
            }
        }

        void insert (int data) {
            if (size >= (n-1)) heap = (int*) realloc (heap, sizeof(int) * ((n*=2)-1));
            heap[++size] = data;
            heapifyUp();
        }

        void extractMax () {
            if (size != -1) {
                cout << "Max: [" << heap[0] << "]\n";
                heap[0] = heap[size--];
                heapifyDown();
            }
            else cout << "Heap Empty\n";
            if (size < (n/2)) heap = (int*) realloc (heap, sizeof(int) * (n/=2));
        }

        void show () {
            for (int i=0; i<=size; i++) cout << "[" << heap[i] << "] ";
            cout << "\n";
        }
};


int main () {
    Heap heap;
    for (int i=1; i<17; i++) heap.insert(i);
    heap.show();
    for (int i=0; i<20; i++) heap.extractMax();
    return 0;
}