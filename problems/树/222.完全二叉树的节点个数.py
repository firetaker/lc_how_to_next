#!/usr/bin/env python3
"""
222. 完全二叉树的节点个数
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def count_nodes(root: Optional[TreeNode]) -> int:
    if not root: return 0
    left_depth = right_depth = 0
    left_node = root
    while left_node:
        left_depth += 1
        left_node = left_node.left
    right_node = root
    while right_node:
        right_depth += 1
        right_node = right_node.right
    if left_depth == right_depth:
        return (1 << left_depth) - 1
    return 1 + count_nodes(root.left) + count_nodes(root.right)

if __name__ == "__main__":
    root1 = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3, TreeNode(6), TreeNode(7)))
    print(count_nodes(root1))  # 7
    print(count_nodes(TreeNode(1)))  # 1
    print(count_nodes(None))  # 0
