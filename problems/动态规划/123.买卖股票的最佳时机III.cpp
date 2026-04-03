#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 123. 买卖股票的最佳时机 III (Best Time to Buy and Sell Stock III)
 *
 * 最多完成两笔交易的最大利润。
 *
 * 动态规划思路：
 * - buy1: 第一次买入后的最大利润
 * - sell1: 第一次卖出后的最大利润
 * - buy2: 第二次买入后的最大利润
 * - sell2: 第二次卖出后的最大利润
 */
int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;

    int buy1 = -prices[0];
    int sell1 = 0;
    int buy2 = -prices[0];
    int sell2 = 0;

    for (int i = 1; i < prices.size(); i++) {
        buy1 = max(buy1, -prices[i]);
        sell1 = max(sell1, buy1 + prices[i]);
        buy2 = max(buy2, sell1 - prices[i]);
        sell2 = max(sell2, buy2 + prices[i]);
    }

    return sell2;
}

int main() {
    // 测试用例1: [3,3,5,0,0,3,1,4]
    vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
    assert(maxProfit(prices1) == 6);
    cout << "测试1通过: [3,3,5,0,0,3,1,4] -> 6" << endl;

    // 测试用例2: 单日价格
    vector<int> prices2 = {1, 2};
    assert(maxProfit(prices2) == 1);
    cout << "测试2通过: [1,2] -> 1" << endl;

    // 测试用例3: 价格持续下跌
    vector<int> prices3 = {7, 6, 4, 3, 1};
    assert(maxProfit(prices3) == 0);
    cout << "测试3通过: [7,6,4,3,1] -> 0" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
