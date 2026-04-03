#!/usr/bin/env python3
"""
309. 最佳买卖股票时机含冷冻期 (Best Time to Buy and Sell Stock with Cooldown)

给定一个整数数组 prices，其中第 i 个元素表示第 i 天的股票价格。
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易：

- 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
- 卖出股票后，你无法在第二天买入股票（即冷冻期为 1 天）。

示例：
输入: prices = [1,2,3,0,2]
输出: 3
解释: 对应的交易顺序为: 买入 -> 卖出 -> 冷冻期 -> 买入 -> 卖出

动态规划思路：
- hold[i]: 第 i 天持有股票的最大利润
- sell[i]: 第 i 天不持有股票且处于冷冻期的最大利润
- free[i]: 第 i 天不持有股票且不处于冷冻期的最大利润

状态转移：
- hold[i] = max(hold[i-1], free[i-1] - prices[i])
- sell[i] = hold[i-1] + prices[i]
- free[i] = max(free[i-1], sell[i-1])

时间复杂度: O(n)
空间复杂度: O(1)
"""


def max_profit(prices: list[int]) -> int:
    """计算含冷冻期的最大利润

    Args:
        prices: 每日股票价格

    Returns:
        最大利润
    """
    if not prices:
        return 0

    n = len(prices)
    if n == 1:
        return 0

    # 空间优化
    hold = -prices[0]   # 持有股票
    sell = 0            # 冷冻期（刚卖出）
    free = 0            # 冷冻期外（未持有且可买入）

    for i in range(1, n):
        prev_hold, prev_sell, prev_free = hold, sell, free
        hold = max(prev_hold, prev_free - prices[i])
        sell = prev_hold + prices[i]
        free = max(prev_free, prev_sell)

    return max(hold, sell, free)


if __name__ == "__main__":
    # 测试用例1: [1,2,3,0,2]
    assert max_profit([1, 2, 3, 0, 2]) == 3

    # 测试用例2: [1,2,4]
    assert max_profit([1, 2, 4]) == 3

    # 测试用例3: 持续下跌
    assert max_profit([4, 3, 2, 1]) == 0

    print("所有测试用例通过!")
