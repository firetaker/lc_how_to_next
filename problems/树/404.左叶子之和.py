#!/usr/bin/env python3
"""
404. 左叶子之和
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def sum_of_left_leaves(root: Optional[TreeNode]) -> int:
    if not root: return 0
    total = 0
    if root.left and not root.left.left and not root.left.right:
        total += root.left.val
    else:
        total += sum_of_left_leaves(root.left)
    total += sum_of_left_leaves(root.right)
    return total

if __name__ == "__main__":
    root1 = TreeNode(3, TreeNode(9, TreeNode(1), TreeNode(3)), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(sum_of_left_leaves(root1))  # 24 (1+15+8)
    root2 = TreeNode(1)
    print(sum_of_left_leaves(root2))  # 0
    print(sum_of_left_leaves(None))  # 0
