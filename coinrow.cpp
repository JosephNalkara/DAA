#include<iostream>
using namespace std;

int max(int a,int b){
	if(a>b){
		 return a;
	}
	else{
		return b;
	}
	//return 0;
}

int CoinRow(int A[],int n){
	int F[n+1];
	F[0]=0;
	F[1]=A[0];
	for(int i=2;i<n+1;i++){
		F[i]=max(A[i-1]+F[i-2],F[i-1]);
	}
	return F[n];
}	
		
int main(){
	int n;
	cout<<"Enter the number of coin:";
	cin>>n;
	int A[n];
	cout<<"Enter the list of coin:";
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	cout<<"The maximum sum is:"<<CoinRow(A,n)<<endl;
}
