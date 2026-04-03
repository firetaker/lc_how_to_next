#!/usr/bin/env python3
"""
91. 解码方法 (Decode Ways)

一条包含字母 A-Z 的消息通过以下映射进行编码：
'A' -> 1
'B' -> 2
...
'Z' -> 26

给定一个只包含数字的字符串 s，计算解码方法的总数。

示例：
输入: s = "12"
输出: 2
解释: 有两种解码方法："AB" (1 2) 或 "L" (12)。

动态规划思路：
- dp[i] 表示 s[0:i] 的解码方法总数
- dp[i] = dp[i-1] if s[i-1] != '0' + dp[i-2] if 10 <= int(s[i-2:i]) <= 26
- 需要处理 '0' 的特殊情况

时间复杂度: O(n)
空间复杂度: O(n) 或 O(1)
"""


def num_decodings(s: str) -> int:
    """计算解码方法的总数

    Args:
        s: 数字字符串

    Returns:
        解码方法的总数
    """
    if not s or s[0] == '0':
        return 0

    n = len(s)
    # dp[i] 表示 s[0:i] 的解码方法总数
    dp = [0] * (n + 1)
    dp[0] = 1  # 空字符串有一种解码方式
    dp[1] = 1 if s[0] != '0' else 0

    for i in range(2, n + 1):
        # 单字符解码
        if s[i - 1] != '0':
            dp[i] += dp[i - 1]

        # 双字符解码
        two_digit = int(s[i - 2:i])
        if 10 <= two_digit <= 26:
            dp[i] += dp[i - 2]

    return dp[n]


if __name__ == "__main__":
    # 测试用例1: "12"
    assert num_decodings("12") == 2

    # 测试用例2: "226"
    assert num_decodings("226") == 3

    # 测试用例3: "0"
    assert num_decodings("0") == 0

    print("所有测试用例通过!")
