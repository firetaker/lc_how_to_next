#!/usr/bin/env python3
"""
49. 字母异位词分组 (Group Anagrams)
题目: 给定字符串数组，将字母异位词分组返回。

算法: 排序字符串作为 key，相同 key 的词为一组
时间复杂度: O(n * k log k)，k 为字符串平均长度
空间复杂度: O(n * k)
"""

from collections import defaultdict

def group_anagrams(strs: list[str]) -> list[list[str]]:
    """
    字母异位词：相同字母不同排列的单词。
    策略：对每个字符串排序，排序结果作为哈希表的 key。
    例如：eat, tea, ate 排序后都是 aet，归为同一组。
    """
    groups = defaultdict(list)
    for s in strs:
        # sorted() 返回字符列表，join 转为字符串作为 key
        key = ''.join(sorted(s))
        groups[key].append(s)
    return list(groups.values())

if __name__ == "__main__":
    # 测试用例
    result = group_anagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
    print(f"输入: [\"eat\", \"tea\", \"tan\", \"ate\", \"nat\", \"bat\"] -> 输出: {result}")
    # 预期: [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']] 或类似分组
    
    result = group_anagrams([""])
    print(f"输入: [\"\"] -> 输出: {result}")  # 预期: [['']]
    
    result = group_anagrams(["a"])
    print(f"输入: [\"a\"] -> 输出: {result}")  # 预期: [['a']]
    
    result = group_anagrams(["abc", "bca", "cab", "def", "fed"])
    print(f"输入: [\"abc\", \"bca\", \"cab\", \"def\", \"fed\"] -> 输出: {result}")
    # 预期: [['abc', 'bca', 'cab'], ['def', 'fed']]
