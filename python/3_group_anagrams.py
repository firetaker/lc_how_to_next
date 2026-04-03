#!/usr/bin/env python3
"""
LeetCode #49: 字母异位词分组
题目: 给定一个字符串数组，将字母异位词组合在一起。
解法: 哈希表 - 将每个字符串排序后作为 key，字母异位词排序后相同，
      因此可以加入同一组。时间 O(n * klogk)，空间 O(n*k)。
      k 为字符串平均长度。
"""


from collections import defaultdict


def group_anagrams(strs: list[str]) -> list[list[str]]:
    """
    排序法: 将字符串排序得到规范形式作为字典 key。
    """
    groups = defaultdict(list)
    for s in strs:
        key = ''.join(sorted(s))
        groups[key].append(s)
    return list(groups.values())


if __name__ == "__main__":
    # 测试用例
    print(group_anagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
    # [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']]
