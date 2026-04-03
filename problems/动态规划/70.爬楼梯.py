#!/usr/bin/env python3
"""
70. 爬楼梯 (Climbing Stairs)

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。有多少种不同的方法可以爬到楼顶？

示例：
输入: n = 2
输出: 2
解释: 有两种方法爬到楼顶:
1. 1阶 + 1阶
2. 2阶

输入: n = 3
输出: 3
解释: 有三种方法爬到楼顶:
1. 1阶 + 1阶 + 1阶
2. 1阶 + 2阶
3. 2阶 + 1阶

动态规划思路：
- dp[i] 表示爬到第 i 阶的方法数
- dp[i] = dp[i-1] + dp[i-2]
- 初始条件: dp[1]=1, dp[2]=2

时间复杂度: O(n)
空间复杂度: O(1)
"""


def climb_stairs(n: int) -> int:
    """计算爬到楼顶的不同方法数

    Args:
        n: 楼梯阶数

    Returns:
        不同的爬楼方法数
    """
    if n <= 2:
        return n

    # 空间优化：从O(n)降到O(1)
    prev2 = 1  # dp[i-2]
    prev1 = 2  # dp[i-1]

    for i in range(3, n + 1):
        current = prev1 + prev2
        prev2 = prev1
        prev1 = current

    return prev1


if __name__ == "__main__":
    # 测试用例1: n=2
    assert climb_stairs(2) == 2

    # 测试用例2: n=3
    assert climb_stairs(3) == 3

    # 测试用例3: n=5
    assert climb_stairs(5) == 8

    print("所有测试用例通过!")
