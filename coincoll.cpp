#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;

   
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;

   
    int board[n][m];


    cout << "Enter the board values (1 for coin, 0 for no coin):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    
    int dp[n][m];

   
    dp[0][0] = board[0][0];

    
    for (int j = 1; j < m; ++j) {
        dp[0][j] = dp[0][j - 1] + board[0][j];
    }

  
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + board[i][0];
    }

  
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i][j];
        }
    }

   
    cout << "Maximum coins collected: " << dp[n - 1][m - 1] << endl;

    return 0;
}
