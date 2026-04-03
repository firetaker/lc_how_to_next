#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 309. 最佳买卖股票时机含冷冻期 (Best Time to Buy and Sell Stock with Cooldown)
 *
 * 卖出股票后无法在第二天买入（冷冻期为1天）。
 *
 * 动态规划思路：
 * - hold[i]: 第 i 天持有股票的最大利润
 * - sell[i]: 第 i 天不持有股票且处于冷冻期
 * - free[i]: 第 i 天不持有股票且不处于冷冻期
 */
int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    if (prices.size() == 1) return 0;

    int n = prices.size();
    int hold = -prices[0];  // 持有股票
    int sell = 0;           // 冷冻期（刚卖出）
    int free = 0;           // 冷冻期外（未持有且可买入）

    for (int i = 1; i < n; i++) {
        int prev_hold = hold;
        int prev_sell = sell;
        int prev_free = free;

        hold = max(prev_hold, prev_free - prices[i]);
        sell = prev_hold + prices[i];
        free = max(prev_free, prev_sell);
    }

    return max({hold, sell, free});
}

int main() {
    // 测试用例1: [1,2,3,0,2]
    vector<int> prices1 = {1, 2, 3, 0, 2};
    assert(maxProfit(prices1) == 3);
    cout << "测试1通过: [1,2,3,0,2] -> 3" << endl;

    // 测试用例2: [1,2,4]
    vector<int> prices2 = {1, 2, 4};
    assert(maxProfit(prices2) == 3);
    cout << "测试2通过: [1,2,4] -> 3" << endl;

    // 测试用例3: 持续下跌
    vector<int> prices3 = {4, 3, 2, 1};
    assert(maxProfit(prices3) == 0);
    cout << "测试3通过: [4,3,2,1] -> 0" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
