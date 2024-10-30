#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string str1, str2;

    
    std::cout << "Enter the first string: ";
    std::getline(std::cin, str1);
    std::cout << "Enter the second string: ";
    std::getline(std::cin, str2);

    int m = str1.length();
    int n = str2.length();

    
    std::vector<std::vector<int>> LCS(m + 1, std::vector<int>(n + 1, 0));

    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            } else {
                LCS[i][j] = std::max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

   
    int index = LCS[m][n];
    std::string lcs(index, ' ');


    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[index - 1] = str1[i - 1]; 
            i--;
            j--;
            index--;
        } else if (LCS[i - 1][j] > LCS[i][j - 1]) {
            i--; 
        } else {
            j--; 
        }
    }

    
    std::cout << "Longest Common Subsequence: " << lcs << std::endl;
    std::cout << "Length of LCS: " << LCS[m][n] << std::endl;

    return 0;
}
 
