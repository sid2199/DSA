#include <iostream>
using namespace std;

class FenwichTree {
    public:
        int size, array[];
        FenwichTree (int size, int data[]) {
            this->size = size+1;
            this->array[size];
            this->array[0] = 0;
            for (int i=0; i<size; i++) this->array[i+1] = data[i];
            for (int i=1;i<this->size; i++) if ((i+lsb(i)) < this->size) this->array[i + lsb(i)] += this->array[i];
        }

        int lsb (int i) {
            return i & -i;
        }

        int prefixSum (int i) {
            int sum = 0;
            while (i > 0) {
                sum += this->array[i];
                i -= lsb(i);
            }
            return sum;
        }

        void getSum (int from, int to) {
            cout << "Sum from " << from-- << " to " << to << " (both inclusive): ";
            cout << prefixSum(to) - prefixSum(from) << "\n";
        }

        void set (int ind, int value) {
            int dif = value - this->array[ind];
            while (ind < this->size) {
                this->array[ind] += dif;
                ind += lsb(ind);
            }
        }

        void show () {
            for (int i=1; i<this->size; i++) cout << "[" << this->array[i] << "] ";
            cout << "\n";
        }
};


int main () {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    FenwichTree ft(size, arr);
    ft.show();
    ft.getSum(0, 10);
    ft.getSum(3, 9);
    ft.set(1, 2);
    ft.show();
    ft.getSum(0, 10);
    return 0;
}