#!/usr/bin/env python3
"""
64. 最小路径和 (Minimum Path Sum)

给定一个包含非负整数的 m x n 网格 grid，请找出一条从左上角到右下角的路径，
使得路径上的数字总和为最小。

每次只能向下或者向右移动一步。

示例：
输入: grid = [[1,3,1],[1,5,1],[4,2,1]]
输出: 7
解释: 路径 1→3→1→1→1 的总和最小。

动态规划思路：
- dp[i][j] 表示到达 (i,j) 的最小路径和
- dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
- 初始条件: dp[0][0] = grid[0][0]

时间复杂度: O(m*n)
空间复杂度: O(n) 优化
"""


def min_path_sum(grid: list[list[int]]) -> int:
    """计算最小路径和

    Args:
        grid: m x n 网格

    Returns:
        最小路径和
    """
    if not grid or not grid[0]:
        return 0

    m, n = len(grid), len(grid[0])

    # 空间优化为一维数组
    dp = [float('inf')] * n
    dp[0] = 0

    for i in range(m):
        for j in range(n):
            if j == 0:
                dp[j] += grid[i][j]
            else:
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1])

    return dp[n - 1]


if __name__ == "__main__":
    # 测试用例1: [[1,3,1],[1,5,1],[4,2,1]]
    grid1 = [[1, 3, 1], [1, 5, 1], [4, 2, 1]]
    assert min_path_sum(grid1) == 7

    # 测试用例2: 单元素
    assert min_path_sum([[5]]) == 5

    # 测试用例3: [[1,2],[1,1]]
    grid3 = [[1, 2], [1, 1]]
    assert min_path_sum(grid3) == 3

    print("所有测试用例通过!")
