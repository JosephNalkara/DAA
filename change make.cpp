#include<iostream>
#include<limits>
using namespace std;

int Min(int a,int b){
	if(a<b){
		 return a;
	}
	else{
		return b;
	}
}

void display(int Arr[],int n){
	for(int i=0;i<n;i++){
		cout<<Arr[i]<<" ";
	}
	cout<<endl;
}

void displayCoins(int D[], int n, int track[]){
    cout << "Coins used to form " << n << ": ";
    while(n > 0){
        cout << D[track[n]] << " ";
        n -= D[track[n]];
    }
    cout << endl;
}

int CoinChange(int n, int D[], int m){
	int F[n+1];
    int track[n+1];  
	F[0] = 0;
	
	for(int i = 1; i <= n; i++){
		int temp = numeric_limits<int>::max();
		int j = 0;
		int chosenCoin = -1;
		
		while(j < m && i >= D[j]){
			if(F[i - D[j]] < temp){
				temp = F[i - D[j]];
				chosenCoin = j;  
			}
			j++;
		}
		F[i] = temp + 1;
		track[i] = chosenCoin;  
	}
	
	display(F, n);
	displayCoins(D, n, track);  
	
	return F[n];
}

int main(){
	cout << "Enter the Coin value for which change is generated: ";
	int n;
	cin >> n;
	
	cout << "Enter the number of denominations: ";
	int m;
	cin >> m;
	
	int D[m];
	cout << "Enter the denominations:" << endl;
	for(int i = 0; i < m; i++){
		cin >> D[i];
	}
	
	int minCoins = CoinChange(n, D, m);
	cout << "Minimum coins required: " << minCoins << endl;
	
	return 0;
}

