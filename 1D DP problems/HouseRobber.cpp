#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    if(nums.size() == 1)    return nums[0];
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    for(int i = 2; i < nums.size(); i++){
        dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
    }
    return dp[nums.size()-1];
}

int main(){
    vector<int> arr = {5,15,6,20,22};
    cout << rob(arr);
    return 0;
}