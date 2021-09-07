#include <iostream>
using namespace std;

int const CAPACITY = 10;
int top = -1;

void push (int data, int stack[]) {
    if (top+1<CAPACITY) stack[++top] = data;
    else cout << "Stack Overflow\n";
}

void pop (int stack[]) {
    if (top>-1) cout << "POP: " << stack[top--] << "\n";
    else cout << "Stack Underflow\n";
}

void peek (int stack[]) {
    if (top>-1) cout << "TOP: " << stack[top] << "\n";
    else cout << "Stack Underflow\n";
}

void show (int stack[]) {
    for (int i=0; i<top+1; i++) cout << "[" << stack[i] << "] ";
    cout << "\n";
}

int main () {
    int stack[10];
    for (int i=1; i<15; i++) push(i, stack);
    show(stack);
    pop(stack);
    peek(stack);
    push(11, stack);
    show(stack);
    int l = top;
    for (int i=0;i<l+2; i++) pop(stack);
    return 0;
}