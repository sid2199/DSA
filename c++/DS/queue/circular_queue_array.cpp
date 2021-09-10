#include <iostream>
#include <cstdlib>
using namespace std;

#define CAPACITY 10

int back = 0, front = 0;

void enqueue (int data, int queue[]) {
    if ((back-front) < CAPACITY) queue[back++%CAPACITY] = data;
    else cout << "No Space Left\n"; 
}

void dequeue (int queue[]) {
    if (front < back) {
        cout << "Dequeue: " << queue[front] << "\n";
        free(&queue[front++%CAPACITY]);
    }
    else cout << "No one in the Queue\n";
}

void show (int queue[]) {
    if (front != back) for (int i=front; i<back; i++) cout << "[" << queue[i%CAPACITY] << "] ";
    else cout << "Empty Queue";
    cout << "\n";
}


int main () {
    int queue[CAPACITY];
    for (int i=1; i<14; i++) enqueue(i, queue);
    show(queue);
    for (int i=0; i<12; i++) dequeue(queue);
    show(queue);
    enqueue(11, queue);
    enqueue(12, queue);
    show(queue);
    return 0;
}