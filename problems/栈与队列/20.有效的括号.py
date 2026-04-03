#!/usr/bin/env python3
"""
20. 有效的括号
算法: 栈
时间复杂度: O(n)
空间复杂度: O(n)
"""
def is_valid(s: str) -> bool:
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}
    for ch in s:
        if ch in mapping:
            top = stack.pop() if stack else '#'
            if mapping[ch] != top:
                return False
        else:
            stack.append(ch)
    return not stack


if __name__ == "__main__":
    print(is_valid("()"))      # 预期: True
    print(is_valid("()[]{}"))  # 预期: True
    print(is_valid("(]"))      # 预期: False
    print(is_valid("([)]"))     # 预期: False
