#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> dp(n + 1, 0);
    int maxi = 0;
    int diagonal = 0;

    for (int i = 1; i <= m; i++) {
        diagonal = 0;

        for (int j = 1; j <= n; j++) {
            int temp = dp[j];

            if (matrix[i-1][j-1] == '1') {
                dp[j] = 1 + min({
                    dp[j],       // Top
                    dp[j-1],     // Left
                    diagonal     // Top-left diagonal
                });

                maxi = max(maxi, dp[j]);
            } else {
                dp[j] = 0;
            }

            diagonal = temp;
        }
    }

    return maxi * maxi;
}

int main(){
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << maximalSquare(matrix);
    return 0;
}
