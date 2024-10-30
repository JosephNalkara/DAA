#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

  
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    
    vector<int> weights(n);
    vector<int> values(n);

     
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

  
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

 
    cout << "Maximum value in the knapsack: " << dp[n][W] << endl;

    
    cout << "Items included in the knapsack: ";
    int w = W;
    for (int i = n; i > 0 && dp[i][w] > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) { 
            cout << i - 1 << " "; 
            w -= weights[i - 1]; 
        }
    }
    cout << endl;

    return 0;
}
