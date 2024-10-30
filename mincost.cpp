#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int m, n;

   
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    
    int cost[m][n];

 
    cout << "Enter the cost matrix values:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    
    int dp[m][n];

    
    dp[0][0] = cost[0][0];

    
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j - 1] + cost[0][j];
    }

    
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + cost[i][0];
    }

   
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = min({dp[i - 1][j],     
                            dp[i][j - 1],     
                            dp[i - 1][j - 1]  
                           }) + cost[i][j];
        }
    }

 
    cout << "Minimum cost to reach cell (" << m - 1 << ", " << n - 1 << "): " << dp[m - 1][n - 1] << endl;

    return 0;
}
