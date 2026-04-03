#!/usr/bin/env python3
"""
226. 翻转二叉树
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def invert_tree(root: Optional[TreeNode]) -> Optional[TreeNode]:
    if not root: return root
    root.left, root.right = root.right, root.left
    invert_tree(root.left)
    invert_tree(root.right)
    return root

def inorder_list(root: Optional[TreeNode]):
    if not root: return []
    return inorder_list(root.left) + [root.val] + inorder_list(root.right)

if __name__ == "__main__":
    root1 = TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(7, TreeNode(6), TreeNode(9)))
    inverted = invert_tree(root1)
    print(inorder_list(inverted))  # [9, 7, 6, 4, 3, 2, 1]
    print(inorder_list(invert_tree(TreeNode(1))))  # [1]
    print(invert_tree(None))  # None
