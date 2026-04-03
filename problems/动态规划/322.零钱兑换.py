#!/usr/bin/env python3
"""
322. 零钱兑换 (Coin Change)

给你一个整数数组 coins 表示不同面额的硬币，和一个整数 amount 表示总金额。
计算并返回凑成总金额所需的最少硬币个数。
如果没有任何硬币组合能组成总金额，返回 -1。

示例：
输入: coins = [1, 2, 5], amount = 11
输出: 3
解释: 11 = 5 + 5 + 1

动态规划思路：
- dp[i] 表示凑成金额 i 所需的最少硬币个数
- dp[i] = min(dp[i], dp[i - coin] + 1) for coin in coins
- 初始条件: dp[0] = 0，其他初始化为无穷大

时间复杂度: O(amount * len(coins))
空间复杂度: O(amount)
"""


def coin_change(coins: list[int], amount: int) -> int:
    """计算凑成总金额所需的最少硬币个数

    Args:
        coins: 硬币面额数组
        amount: 总金额

    Returns:
        最少硬币个数，如果无法凑成则返回 -1
    """
    # dp[i] 表示凑成金额 i 所需的最少硬币个数
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0

    for i in range(1, amount + 1):
        for coin in coins:
            if i - coin >= 0 and dp[i - coin] != float('inf'):
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[amount] if dp[amount] != float('inf') else -1


if __name__ == "__main__":
    # 测试用例1: [1,2,5], 11
    assert coin_change([1, 2, 5], 11) == 3

    # 测试用例2: 无法凑成
    assert coin_change([2], 3) == -1

    # 测试用例3: 只需要一个硬币
    assert coin_change([1], 0) == 0

    print("所有测试用例通过!")
