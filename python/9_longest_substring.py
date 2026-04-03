#!/usr/bin/env python3
"""
LeetCode #3: 无重复字符的最长子串
题目: 给定一个字符串，找出不含重复字符的最长子串长度。
解法: 滑动窗口 + 哈希表 - 使用左右指针维护一个窗口，
      用字典/集合记录窗口内字符出现的次数。遇到重复字符时
      收缩左端点直到无重复。时间 O(n)，空间 O(min(n, sigma))。
"""


def length_of_longest_substring(s: str) -> int:
    """
    滑动窗口: right 扩展窗口，遇到重复字符时收缩 left。
    用字典记录字符最新出现位置。
    """
    char_index = {}  # char -> latest index
    left = 0
    max_len = 0
    for right, ch in enumerate(s):
        if ch in char_index and char_index[ch] >= left:
            left = char_index[ch] + 1
        char_index[ch] = right
        max_len = max(max_len, right - left + 1)
    return max_len


if __name__ == "__main__":
    # 测试用例
    print(length_of_longest_substring("abcabcbb"))  # 3 ("abc")
    print(length_of_longest_substring("bbbbb"))     # 1 ("b")
    print(length_of_longest_substring("pwwkew"))    # 3 ("wke")
