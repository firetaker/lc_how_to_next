#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/**
 * 322. 零钱兑换 (Coin Change)
 *
 * 给定硬币面额数组 coins 和总金额 amount，计算凑成总金额所需的最少硬币个数。
 *
 * 动态规划思路：
 * - dp[i] 表示凑成金额 i 所需的最少硬币个数
 * - dp[i] = min(dp[i], dp[i - coin] + 1)
 */
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    // 测试用例1: [1,2,5], 11
    vector<int> coins1 = {1, 2, 5};
    assert(coinChange(coins1, 11) == 3);
    cout << "测试1通过: [1,2,5], 11 -> 3" << endl;

    // 测试用例2: 无法凑成
    vector<int> coins2 = {2};
    assert(coinChange(coins2, 3) == -1);
    cout << "测试2通过: [2], 3 -> -1" << endl;

    // 测试用例3: 只需要一个硬币
    vector<int> coins3 = {1};
    assert(coinChange(coins3, 0) == 0);
    cout << "测试3通过: [1], 0 -> 0" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
