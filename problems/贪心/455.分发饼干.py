#!/usr/bin/env python3
"""
455. 分发饼干
算法: 贪心
时间复杂度: O(n log n)
空间复杂度: O(1)
"""
def find_content_children(g: list[int], s: list[int]) -> int:
    g.sort()
    s.sort()
    i = j = 0
    while i < len(g) and j < len(s):
        if s[j] >= g[i]:
            i += 1
        j += 1
    return i


if __name__ == "__main__":
    print(find_content_children([1, 2, 3], [1, 1]))  # 预期: 1
    print(find_content_children([1, 2], [1, 2, 3]))  # 预期: 2
    print(find_content_children([10, 9, 8, 7], [5, 6, 7, 8]))  # 预期: 2
