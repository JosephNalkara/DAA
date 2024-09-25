#include <iostream>
#include <vector>
using namespace std;


void heapify(int arrr[], int n, int i) {
    int largest = i;    
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    
    if (left < n && arrr[left] > arrr[largest])
        largest = left;

   
    if (right < n && arrr[right] > arrr[largest])
        largest = right;

    
    if (largest != i) {
      
        swap(arrr[i], arrr[largest]);

      
        heapify(arrr, n, largest);
    }
}


void heapSort(int arrr[]) {
    int n =10;

   
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arrr, n, i);


    for (int i = n - 1; i >= 0; i--) {
        
        swap(arrr[0], arrr[i]);

        
        heapify(arrr, i, 0);
    }
}


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


void printArray(int arrr[]) {
    for (int i = 0; i < 10; ++i) {
        cout << arrr[i] << " ";
    }
    cout << endl;
}

int main() {
   
    int arr[10];
    cout<<"enter the elements:"<<endl;
    for(int i=0;i<10;i++){
       cin>>arr[i];}
    cout << "the array entered: ";
    printArray(arr);

    heapSort(arr);

    cout << "the array after sorting: ";
    printArray(arr);

    return 0;
}

