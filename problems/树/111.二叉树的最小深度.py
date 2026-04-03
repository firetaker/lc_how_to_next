#!/usr/bin/env python3
"""
111. 二叉树的最小深度
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def min_depth(root: Optional[TreeNode]) -> int:
    if not root: return 0
    if not root.left: return 1 + min_depth(root.right)
    if not root.right: return 1 + min_depth(root.left)
    return 1 + min(min_depth(root.left), min_depth(root.right))

if __name__ == "__main__":
    root1 = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(min_depth(root1))  # 2
    root2 = TreeNode(1, None, TreeNode(2))
    print(min_depth(root2))  # 2
    print(min_depth(None))  # 0
