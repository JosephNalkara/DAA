#include <iostream>
using namespace std;

int fib(int n)
{
    if(n==1){
        return 0;}
    if(n==2){
      return 1;}
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cout << "Enter the limit:" << endl;
    cin >> n;
    
    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
    } else {
        cout << n << "th Fibonacci Number: " << fib(n) << endl;
    }
    
    return 0;
}

