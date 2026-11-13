#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPerfect(int n){
    int sqr = sqrt(n);
    if((sqr*sqr) == n)
        return 1;
    return 0;
}
int numSquares(int n, vector<int> &dp){
    if(isPerfect(n))    return dp[n] = 1;
    if(dp[n] != -1) return dp[n];
    int mini = n;
    for(int i = 1; i*i <= n; i++){
        int count = numSquares(i*i,dp) + numSquares(n-i*i,dp);
        mini = min(mini, count);
    }
    return dp[n] = mini;
}
int numSquares(int n) {
    vector<int> dp(n+1, -1);
    numSquares(n, dp);
    return dp[n];
}

int main(){
  int n;
  cin >> n;
  cout << numSquares(n);
  return 0;
}
