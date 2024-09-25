#include<iostream>
using namespace std;
void linearSearch(int array[],int x){
for(int i=1;i<11;i++){
 if(array[i]==x){
  cout<<"the element found at index:"<<i<<endl;
 }
 }}
int main(){
int c;
int lst[10];
cout << "Enter a 10 element array:" << endl;
    for(int i = 0; i < 10; i++) {
        cin >> lst[i];}
cout<<"enter the element to be searched:"<<endl;
cin>>c ;
linearSearch(lst,c);
return 0;}
