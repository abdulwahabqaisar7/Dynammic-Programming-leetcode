
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int> &arr) {
    int n = arr.size();

    vector<int> hi(n);
    vector<int> lo(n);

    hi[0] = arr[0];
    lo[0] = arr[0];

    int ans = arr[0];

    for(int i = 1; i < n; i++) {

        hi[i] = max({arr[i],
                     arr[i] * hi[i-1],
                     arr[i] * lo[i-1]});

        lo[i] = min({arr[i],
                     arr[i] * hi[i-1],
                     arr[i] * lo[i-1]});

        ans = max(ans, hi[i]);
    }

    return ans;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};

    cout << maxProduct(nums);

    return 0;
}
