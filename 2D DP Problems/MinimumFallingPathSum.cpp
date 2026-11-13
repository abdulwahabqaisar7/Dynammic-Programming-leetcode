#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if(n == 1)  return matrix[0][0];
    for(int i = n-2; i >= 0; i--){
        matrix[i][0] = matrix[i][0]+min(matrix[i+1][0],matrix[i+1][1]);
        for(int j = 1; j < n-1; j++){
            matrix[i][j] = matrix[i][j] + min(matrix[i+1][j-1],min(matrix[i+1][j],matrix[i+1][j+1]));
        }
        matrix[i][n-1] = matrix[i][n-1] + min(matrix[i+1][n-1],matrix[i+1][n-2]);
    }
    int result = matrix[0][0];
    for(int i = 1; i < n; i++){
        result = min(result, matrix[0][i]);
    }
    return result;
}

int main(){
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << minFallingPathSum(matrix);
    return 0;
}