#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int countSquares(vector<vector<int>>& matrix) {
    int sum = 0;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j] != 0 && i > 0 && j > 0){
                matrix[i][j] = 1 + min(matrix[i-1][j-1],min(matrix[i-1][j], matrix[i][j-1]));
            }
            sum += matrix[i][j];
        }
    }
    return sum;
}
int main(){
    vector<vector<int>> matrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    cout << countSquares(matrix);
    return 0;
}