#!/usr/bin/env python3
"""
76. 最小覆盖子串
算法: 滑动窗口 + 哈希表（双计数器）
时间复杂度: O(n)
空间复杂度: O(1)（字符集大小固定）
"""
from collections import Counter


def min_window(s: str, t: str) -> str:
    need = Counter(t)
    window = Counter()
    left = 0
    valid = 0
    start = 0
    min_len = float('inf')

    for right, ch in enumerate(s):
        if ch in need:
            window[ch] += 1
            if window[ch] >= need[ch]:
                valid += 1

        while valid == len(need):
            if right - left + 1 < min_len:
                start = left
                min_len = right - left + 1
            if s[left] in need:
                if window[s[left]] <= need[s[left]]:
                    valid -= 1
                window[s[left]] -= 1
            left += 1

    return s[start:start + min_len] if min_len != float('inf') else ""


if __name__ == "__main__":
    print(min_window("ADOBECODEBANC", "ABC"))  # 预期: "BANC"
    print(min_window("a", "a"))               # 预期: "a"
    print(min_window("a", "b"))               # 预期: ""
