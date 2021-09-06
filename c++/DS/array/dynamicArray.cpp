#include <iostream>
#include <cstdlib>
using namespace std;


int main () {
    bool run = true;
    int x, y, ind, n = 0, max = 1;
    int *arr = (int*) malloc (sizeof(int)*max);
    while (run) {
        cout << "1. insert\t";
        cout << "2. change\t";
        cout << "3. show array\t";
        cout << "4. size of array\t";
        cout << "5. Exit\n";
        cin >> x;
        switch (x) {
            case 1:
                cout << "Enter the number: ";
                cin >> y;
                if (n<max) arr[n++] = y;
                else {
                    arr = (int*) realloc (arr, sizeof(int)*(max*=2));
                    arr[n++] = y;
                }
                break;
            case 2:
                cout << "Enter the index: ";
                cin >> ind;
                cout << "Enter the value: ";
                cin >> y;
                arr[ind] = y;
                break;
            case 3:
                for (int i=0; i<n; i++) cout << "[" << arr[i] << "] ";
                cout<<"\n";
                break;
            case 4:
                cout << "Current size: " << n << "\n";
                break;
            case 5:
                run = false;
                cout << "[Exit]";
                break;
        }
    }
    return 0;
}