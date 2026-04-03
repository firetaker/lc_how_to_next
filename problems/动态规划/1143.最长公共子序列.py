#!/usr/bin/env python3
"""
1143. 最长公共子序列 (Longest Common Subsequence)

给定两个字符串 text1 和 text2，返回它们的最长公共子序列的长度。
一个字符串的子序列是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除）后组成的新字符串。

示例：
输入: text1 = "abcde", text2 = "ace"
输出: 3
解释: 最长公共子序列是 "ace"，长度是 3。

动态规划思路：
- dp[i][j] 表示 text1[0:i] 和 text2[0:j] 的最长公共子序列长度
- if text1[i-1] == text2[j-1]: dp[i][j] = dp[i-1][j-1] + 1
- else: dp[i][j] = max(dp[i-1][j], dp[i][j-1])

时间复杂度: O(m*n)
空间复杂度: O(m*n)
"""


def longest_common_subsequence(text1: str, text2: str) -> int:
    """计算最长公共子序列的长度

    Args:
        text1: 第一个字符串
        text2: 第二个字符串

    Returns:
        最长公共子序列的长度
    """
    m, n = len(text1), len(text2)

    # 空间优化：从O(m*n)降到O(n)
    dp = [0] * (n + 1)

    for i in range(1, m + 1):
        prev = 0  # 保存 dp[i-1][j-1]
        for j in range(1, n + 1):
            temp = dp[j]  # 保存旧的 dp[j] (即 dp[i-1][j])
            if text1[i - 1] == text2[j - 1]:
                dp[j] = prev + 1
            else:
                dp[j] = max(dp[j], dp[j - 1])
            prev = temp

    return dp[n]


if __name__ == "__main__":
    # 测试用例1: "abcde" 和 "ace"
    assert longest_common_subsequence("abcde", "ace") == 3

    # 测试用例2: "abc" 和 "def"
    assert longest_common_subsequence("abc", "def") == 0

    # 测试用例3: "abcabc" 和 "abcabc"
    assert longest_common_subsequence("abcabc", "abcabc") == 6

    print("所有测试用例通过!")
