#!/usr/bin/env python3
"""
63. 不同路径 II (Unique Paths II)

一个机器人位于 m x n 网格的左上角（起始点在下图中标记为 "Start"）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角。
网格中有些格子是障碍物，如果格子中有障碍物，则该格子不可通过。

给定 m x n 的网格和一个起始机器人位置，返回不同路径的数量。
答案保证是个非负整数。

动态规划思路：
- dp[i][j] 表示到达 (i,j) 的不同路径数
- 如果 (i,j) 是障碍: dp[i][j] = 0
- 否则: dp[i][j] = dp[i-1][j] + dp[i][j-1]

时间复杂度: O(m*n)
空间复杂度: O(n) 优化
"""


def unique_paths_with_obstacles(grid: list[list[int]]) -> int:
    """计算有障碍物时不同路径的数量

    Args:
        grid: m x n 网格，1 表示障碍物，0 表示可通行

    Returns:
        不同路径的数量
    """
    if not grid or not grid[0]:
        return 0

    m, n = len(grid), len(grid[0])

    # 如果起点或终点有障碍，直接返回 0
    if grid[0][0] == 1 or grid[m - 1][n - 1] == 1:
        return 0

    # dp[j] 表示当前行的路径数
    dp = [0] * n
    dp[0] = 1

    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                dp[j] = 0
            elif j > 0:
                dp[j] += dp[j - 1]

    return dp[n - 1]


if __name__ == "__main__":
    # 测试用例1: 有障碍物
    grid1 = [
        [0, 0, 0],
        [0, 1, 0],
        [0, 0, 0]
    ]
    assert unique_paths_with_obstacles(grid1) == 2

    # 测试用例2: 起点即障碍
    grid2 = [[1, 0]]
    assert unique_paths_with_obstacles(grid2) == 0

    # 测试用例3: 无障碍
    grid3 = [[0, 0], [0, 0]]
    assert unique_paths_with_obstacles(grid3) == 2

    print("所有测试用例通过!")
