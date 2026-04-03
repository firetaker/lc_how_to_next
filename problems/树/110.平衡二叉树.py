#!/usr/bin/env python3
"""
110. 平衡二叉树
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_balanced(root: Optional[TreeNode]) -> bool:
    def dfs(node: Optional[TreeNode]) -> int:
        if not node: return 0
        left = dfs(node.left)
        if left == -1: return -1
        right = dfs(node.right)
        if right == -1 or abs(left - right) > 1: return -1
        return max(left, right) + 1
    return dfs(root) != -1

if __name__ == "__main__":
    root1 = TreeNode(1, TreeNode(2, TreeNode(3), TreeNode(3)), TreeNode(2))
    print(is_balanced(root1))  # False
    root2 = TreeNode(1, TreeNode(2, TreeNode(3), TreeNode(3)), TreeNode(2, None, TreeNode(9)))
    print(is_balanced(root2))  # True
    print(is_balanced(None))  # True
