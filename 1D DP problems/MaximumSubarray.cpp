#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSum(vector<int>&arr){
    vector<int> dp(arr.size());
    dp[0] = arr[0];
    for(int i = 1; i < arr.size(); i++){
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
    }
    return dp[arr.size()-1];
}
int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSum(arr);
}