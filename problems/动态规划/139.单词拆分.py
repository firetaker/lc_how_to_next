#!/usr/bin/env python3
"""
139. 单词拆分 (Word Break)

给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
请你判断是否可以利用字典中出现的单词拼接出 s 。

注意：
- 字典中出现的单词可以重复使用
- 拼接时不需要使用字典中的全部单词

示例：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true，因为 "leetcode" 可以由 "leet" 和 "code" 拼接而成。

动态规划思路：
- dp[i] 表示 s[0:i] 是否可以由 wordDict 拼接而成
- dp[i] = True if exists j in [0,i) such that dp[j] and s[j:i] in wordDict
- 从左到右计算

时间复杂度: O(n^2 * m) 其中 m 是字典中单词的平均长度
空间复杂度: O(n)
"""


def word_break(s: str, word_dict: list[str]) -> bool:
    """判断字符串是否可以被字典中的单词拼接而成

    Args:
        s: 目标字符串
        word_dict: 单词字典

    Returns:
        如果可以拼接返回 True，否则返回 False
    """
    word_set = set(word_dict)
    n = len(s)

    # dp[i] 表示 s[0:i] 是否可以由 wordDict 拼接而成
    dp = [False] * (n + 1)
    dp[0] = True

    for i in range(1, n + 1):
        for j in range(i):
            if dp[j] and s[j:i] in word_set:
                dp[i] = True
                break

    return dp[n]


if __name__ == "__main__":
    # 测试用例1: "leetcode", ["leet", "code"]
    assert word_break("leetcode", ["leet", "code"]) == True

    # 测试用例2: "applepenapple", ["apple", "pen"]
    assert word_break("applepenapple", ["apple", "pen"]) == True

    # 测试用例3: 无法拆分
    assert word_break("catsandog", ["cats", "dog", "sand", "and", "cat"]) == False

    print("所有测试用例通过!")
