#include <iostream>
#include <vector>
using namespace std;

int numWays(int steps, int arrLen) {
    int maxPos = min(steps/2, arrLen-1);
    vector<int> dp(maxPos+1, 0), ndp(maxPos+1, 0);
    dp[0] = 1;
    const int MOD = 1e9+7;
    for (int s = 1; s <= steps; s++) {
        fill(ndp.begin(), ndp.end(), 0);
        for (int p = 0; p <= maxPos; p++) {
            ndp[p] = (ndp[p] + dp[p]) % MOD;
            if (p > 0) ndp[p] = (ndp[p] + dp[p-1]) % MOD;
            if (p < maxPos) ndp[p] = (ndp[p] + dp[p+1]) % MOD;
        }
        dp.swap(ndp);
    }
    return dp[0];
}

int main() {
    // 测试用例
    cout << numWays(3, 2) << endl;  // 预期: 3
    cout << numWays(2, 4) << endl;  // 预期: 2
    cout << numWays(4, 2) << endl;  // 预期: 8
    return 0;
}
