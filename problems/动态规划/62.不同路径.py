#!/usr/bin/env python3
"""
62. 不同路径 (Unique Paths)

一个机器人位于 m x n 网格的左上角（起始点在下图中标记为 "Start"）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 "Finish"）。

问总共有多少条不同的路径？

示例：
输入: m = 3, n = 7
输出: 28

动态规划思路：
- dp[i][j] 表示到达 (i,j) 的不同路径数
- dp[i][j] = dp[i-1][j] + dp[i][j-1]
- 初始条件: dp[0][j] = 1, dp[i][0] = 1

时间复杂度: O(m*n)
空间复杂度: O(m*n) 或 O(n) 优化
"""


def unique_paths(m: int, n: int) -> int:
    """计算不同路径的数量

    Args:
        m: 网格行数
        n: 网格列数

    Returns:
        不同路径的数量
    """
    # 空间优化为一维数组
    dp = [1] * n

    for i in range(1, m):
        for j in range(1, n):
            dp[j] += dp[j - 1]

    return dp[n - 1]


if __name__ == "__main__":
    # 测试用例1: 3x7 网格
    assert unique_paths(3, 7) == 28

    # 测试用例2: 1x1 网格
    assert unique_paths(1, 1) == 1

    # 测试用例3: 2x2 网格
    assert unique_paths(2, 2) == 2

    print("所有测试用例通过!")
