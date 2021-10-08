#include <iostream>
using namespace std;

void bubblesort (int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main () {
    int array[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(array)/sizeof(array[0]);
    for (int i=0; i<n; i++) cout << "[" << array[i] << "] ";
    cout << "\n";
    bubblesort(array, n);
    for (int i=0; i<n; i++) cout << "[" << array[i] << "] ";
    cout << "\n";
    return 0;
}