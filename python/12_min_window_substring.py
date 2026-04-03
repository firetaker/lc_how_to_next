#!/usr/bin/env python3
"""
LeetCode #76: 最小覆盖子串
题目: 在 s 中找出包含 t 所有字符的最小子串。
解法: 滑动窗口 + 字符计数 - 用 need 数组记录 t 中各字符的需求量，
      window 记录当前窗口中各字符的数量。维护 less 变量表示
      窗口中还有多少种字符的需求未满足。窗口扩展到满足条件后收缩。
      时间 O(n)，空间 O(1)。
"""


def minWindow(s: str, t: str) -> str:
    """
    滑动窗口: need 记录 t 的字符需求，less 表示"未满足需求的字符种类数"。
    right 扩展窗口；less==0 时收缩 left 找最小。
    """
    need = [0] * 128
    window = [0] * 128
    for ch in t:
        need[ord(ch)] += 1
    less = sum(1 for x in need if x > 0)  # 有多少种字符还有未满足需求
    left = 0
    min_len = float('inf')
    min_start = 0
    for right, ch in enumerate(s):
        idx = ord(ch)
        if need[idx] > 0:
            window[idx] += 1
            if window[idx] == need[idx]:
                less -= 1
        # 尝试收缩窗口
        while less == 0:
            cur_len = right - left + 1
            if cur_len < min_len:
                min_len = cur_len
                min_start = left
            left_ch = s[left]
            left_idx = ord(left_ch)
            if need[left_idx] > 0:
                if window[left_idx] == need[left_idx]:
                    less += 1
                window[left_idx] -= 1
            left += 1
    return s[min_start:min_start + min_len] if min_len != float('inf') else ""


if __name__ == "__main__":
    print(minWindow("ADOBECODEBANC", "ABC"))  # "BANC"
    print(minWindow("a", "a"))               # "a"
    print(minWindow("a", "aa"))               # ""
