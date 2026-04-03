#!/usr/bin/env python3
"""
3. 无重复字符的最长子串
算法: 滑动窗口 + 哈希表
时间复杂度: O(n)
空间复杂度: O(min(m, n))
"""
def length_of_longest_substring(s: str) -> int:
    char_index = {}
    left = 0
    max_len = 0
    for right, ch in enumerate(s):
        if ch in char_index and char_index[ch] >= left:
            left = char_index[ch] + 1
        char_index[ch] = right
        max_len = max(max_len, right - left + 1)
    return max_len


if __name__ == "__main__":
    print(length_of_longest_substring("abcabcbb"))  # 预期: 3
    print(length_of_longest_substring("bbbbb"))    # 预期: 1
    print(length_of_longest_substring("pwwkew"))  # 预期: 3
    print(length_of_longest_substring(""))         # 预期: 0
