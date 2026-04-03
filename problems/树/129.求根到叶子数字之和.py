#!/usr/bin/env python3
"""
129. 求根到叶子数字之和
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def sum_numbers(root: Optional[TreeNode]) -> int:
    result = 0
    def dfs(node: Optional[TreeNode], num: int):
        nonlocal result
        if not node: return
        num = num * 10 + node.val
        if not node.left and not node.right: result += num
        dfs(node.left, num)
        dfs(node.right, num)
    dfs(root, 0)
    return result

if __name__ == "__main__":
    root1 = TreeNode(1, TreeNode(2), TreeNode(3))
    print(sum_numbers(root1))  # 25
    print(sum_numbers(TreeNode(5)))  # 5
    print(sum_numbers(None))  # 0
