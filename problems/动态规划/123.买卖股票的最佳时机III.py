#!/usr/bin/env python3
"""
123. 买卖股票的最佳时机 III (Best Time to Buy and Sell Stock III)

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成两笔交易。

注意：
- 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例：
输入: prices = [3,3,5,0,0,3,1,4]
输出: 6
解释: 在第 4 天买入 (price=0)，第 6 天卖出 (price=3)，利润 = 3
      在第 7 天买入 (price=1)，第 8 天卖出 (price=4)，利润 = 3

动态规划思路：
- 用四个变量分别记录两次交易的状态
- buy1: 第一次买入后的最大利润
- sell1: 第一次卖出后的最大利润
- buy2: 第二次买入后的最大利润
- sell2: 第二次卖出后的最大利润

时间复杂度: O(n)
空间复杂度: O(1)
"""


def max_profit(prices: list[int]) -> int:
    """计算最大利润（最多两笔交易）

    Args:
        prices: 每日股票价格

    Returns:
        最大利润
    """
    if not prices:
        return 0

    buy1 = -prices[0]   # 第一次买入后的最大利润
    sell1 = 0           # 第一次卖出后的最大利润
    buy2 = -prices[0]   # 第二次买入后的最大利润
    sell2 = 0           # 第二次卖出后的最大利润

    for price in prices[1:]:
        buy1 = max(buy1, -price)
        sell1 = max(sell1, buy1 + price)
        buy2 = max(buy2, sell1 - price)
        sell2 = max(sell2, buy2 + price)

    return sell2


if __name__ == "__main__":
    # 测试用例1: [3,3,5,0,0,3,1,4]
    assert max_profit([3, 3, 5, 0, 0, 3, 1, 4]) == 6

    # 测试用例2: 单日价格
    assert max_profit([1, 2]) == 1

    # 测试用例3: 价格持续下跌
    assert max_profit([7, 6, 4, 3, 1]) == 0

    print("所有测试用例通过!")
