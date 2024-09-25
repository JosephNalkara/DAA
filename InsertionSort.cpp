#include<iostream>
using namespace std;
void insertionsort(int array[],int size){
    int j;
    for(int a = 1; a <=size-1; a++) {
        j=a-1;
        int key = array[a];
        while(j>=0 && array[j]>key){
        	array[j+1]=array[j];
                j-=1;
                
        }
        array[j+1]=key;
        }
    cout << "The sorted list is: ";
    for(int b = 0; b < size; b++) {
        cout << array[b] << " ";
    }
    cout << endl;
}

int main() {
int x;
cout<<"Enter a limit  :";
cin>>x;
    int lst[x];
    cout << "Enter the  element :"<<endl ;
    for(int i = 0; i < x; i++) {
        cin >> lst[i];
    }
    
    insertionsort(lst, x);
    return 0;
}
