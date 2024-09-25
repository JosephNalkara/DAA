#include<iostream>
using namespace std;

void bubbleSort(int array[], int size) {
    for(int a = 0; a <= size - 1; a++) {
        for(int j = 0; j < size - a - 1; j++) {
            if(array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
   
    cout << "The sorted list is: ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int lst[10];
    cout << "Enter a 10 element array:" << endl;
    for(int i = 0; i < 10; i++) {
        cin >> lst[i];
    }
    bubbleSort(lst, 10);
    return 0;
}

