#!/usr/bin/env python3
"""
14. 最长公共前缀
"""


def longest_common_prefix(strs: list[str]) -> str:
    if not strs:
        return ''
    for i in range(len(strs[0])):
        for j in range(1, len(strs)):
            if i >= len(strs[j]) or strs[j][i] != strs[0][i]:
                return strs[0][:i]
    return strs[0]


if __name__ == "__main__":
    # 测试用例
    print(longest_common_prefix(["flower", "flow", "flight"]))  # 预期: "fl"
    print(longest_common_prefix(["dog", "racecar", "car"]))      # 预期: ""
    print(longest_common_prefix(["a"]))                           # 预期: "a"
