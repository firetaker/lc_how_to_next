#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n) {
    vector<int> dp(n+1, 0);
    for (int i = 1; i <= n; i++)
        dp[i] = dp[i>>1] + (i & 1);
    return dp;
}

int main() {
    // 测试用例
    auto r1 = countBits(2);
    for (int x : r1) cout << x << " "; cout << endl;  // 预期: 0 1 1
    auto r2 = countBits(5);
    for (int x : r2) cout << x << " "; cout << endl;  // 预期: 0 1 1 2 1 2
    auto r3 = countBits(0);
    for (int x : r3) cout << x << " "; cout << endl;  // 预期: 0
    auto r4 = countBits(1);
    for (int x : r4) cout << x << " "; cout << endl;  // 预期: 0 1
    return 0;
}
