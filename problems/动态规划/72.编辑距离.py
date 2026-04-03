#!/usr/bin/env python3
"""
72. 编辑距离 (Edit Distance)

给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数。

你可以对一个单词执行以下三种操作：
1. 插入一个字符
2. 删除一个字符
3. 替换一个字符

示例：
输入: word1 = "horse", word2 = "ros"
输出: 3
解释:
horse -> rorse (将 'h' 替换为 'r')
rorse -> ros (删除 'r')
ros -> ros (无需操作)

动态规划思路：
- dp[i][j] 表示 word1[0:i] 转换成 word2[0:j] 的最少操作数
- if word1[i-1] == word2[j-1]: dp[i][j] = dp[i-1][j-1]
- else: dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
  - 对应删除、插入、替换操作

时间复杂度: O(m*n)
空间复杂度: O(m*n)
"""


def min_distance(word1: str, word2: str) -> int:
    """计算编辑距离

    Args:
        word1: 第一个单词
        word2: 第二个单词

    Returns:
        最少操作数
    """
    m, n = len(word1), len(word2)

    # dp[i][j] 表示 word1[0:i] 转换成 word2[0:j] 的最少操作数
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    # 初始化边界
    for i in range(m + 1):
        dp[i][0] = i  # 删除 i 个字符
    for j in range(n + 1):
        dp[0][j] = j  # 插入 j 个字符

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if word1[i - 1] == word2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1

    return dp[m][n]


if __name__ == "__main__":
    # 测试用例1: horse -> ros
    assert min_distance("horse", "ros") == 3

    # 测试用例2: 相同单词
    assert min_distance("intention", "intention") == 0

    # 测试用例3: 空字符串
    assert min_distance("", "abc") == 3

    print("所有测试用例通过!")
