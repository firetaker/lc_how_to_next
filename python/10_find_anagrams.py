#!/usr/bin/env python3
"""
LeetCode #438: 找到字符串中所有字母异位词
题目: 给定字符串 s 和 p，找出 s 中所有 p 的字母异位词（异位词即为排列）。
解法: 不定长滑动窗口 + 字符计数 - 用数组/字典记录目标字符串 p 的字符频次，
      在 s 上维护一个等长窗口，字符频次匹配时记录起点索引。
      时间 O(n)，空间 O(1)（字符集大小固定为26）。
"""


def find_anagrams(s: str, p: str) -> list[int]:
    """
    不定长滑窗 + 计数: 用 need 记录 p 的字符需求，
    valid 记录当前窗口中满足需求的字符种类数。
    """
    need = [0] * 26
    window = [0] * 26
    a_ord = ord('a')
    for ch in p:
        need[ord(ch) - a_ord] += 1
    left, right = 0, 0
    valid = 0
    result = []
    while right < len(s):
        ch = s[right]
        idx = ord(ch) - a_ord
        right += 1
        if need[idx] > 0:
            window[idx] += 1
            if window[idx] == need[idx]:
                valid += 1
        # 收缩窗口使长度等于 p 的长度
        while right - left >= len(p):
            if valid == sum(1 for x in need if x > 0):
                result.append(left)
            ch = s[left]
            idx = ord(ch) - a_ord
            left += 1
            if need[idx] > 0:
                if window[idx] == need[idx]:
                    valid -= 1
                window[idx] -= 1
    return result


if __name__ == "__main__":
    # 测试用例
    print(find_anagrams("cbaebabacd", "abc"))  # [0, 6]
    print(find_anagrams("abab", "ab"))        # [0, 1, 2]
