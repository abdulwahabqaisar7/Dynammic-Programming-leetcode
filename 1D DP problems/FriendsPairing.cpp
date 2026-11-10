#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Pair(int n){
    if(n <= 2)  return n;
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1]+(i-1)*dp[i-2]);
    }
    return dp[n];
}

int main(){
    int n = 4;
    cout << Pair(n);
    return 0;
}