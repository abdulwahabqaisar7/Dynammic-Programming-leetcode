#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        int INF = amount + 1;
        vector<vector<int>> dp(n + 1,
                               vector<int>(amount + 1, INF));
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= amount; j++) {

                // Don't take current coin
                dp[i][j] = dp[i-1][j];

                // Take current coin
                if(j >= coins[i-1]) {
                    dp[i][j] = min(
                        dp[i][j],
                        1 + dp[i][j-coins[i-1]]
                    );
                }
            }
        }

        if(dp[n][amount] == INF)
            return -1;

        return dp[n][amount];
    }
};
int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;
    Solution s;
    cout << s.coinChange(coins, amount);
    return 0;
}