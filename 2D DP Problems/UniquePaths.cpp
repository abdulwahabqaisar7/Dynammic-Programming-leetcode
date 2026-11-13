#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return path(0,0,m,n,dp);
}
int path(int i, int j, int m, int n, vector<vector<int>> &dp){
    if(i >= m || j >= n)    return 0;
    if(i >= m-1 && j >= n-1)    return 1;
    if(dp[i][j] != -1)  return dp[i][j];
    int rightways = path(i, j+1, m, n, dp);
    int leftways = path(i+1, j, m, n, dp);
    return dp[i][j] = rightways+leftways;
}

int main(){
    int m = 3;  
    int n = 7;
    cout << uniquePaths(m,n);
    return 0;
}