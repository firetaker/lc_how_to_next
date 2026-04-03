#!/usr/bin/env python3
"""
124. 二叉树中的最大路径和
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def max_path_sum(root: Optional[TreeNode]) -> int:
    result = float('-inf')
    def dfs(node: Optional[TreeNode]) -> int:
        nonlocal result
        if not node: return 0
        left  = max(0, dfs(node.left))
        right = max(0, dfs(node.right))
        result = max(result, left + right + node.val)
        return max(left, right) + node.val
    dfs(root)
    return result

if __name__ == "__main__":
    root1 = TreeNode(-10, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(max_path_sum(root1))  # 42
    print(max_path_sum(TreeNode(1)))  # 1
    print(max_path_sum(None))  # 0
