#!/usr/bin/env python3
"""
617. 合并二叉树
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def merge_trees(t1: Optional[TreeNode], t2: Optional[TreeNode]) -> Optional[TreeNode]:
    if not t1: return t2
    if not t2: return t1
    t1.val += t2.val
    t1.left  = merge_trees(t1.left, t2.left)
    t1.right = merge_trees(t1.right, t2.right)
    return t1

def inorder_list(root: Optional[TreeNode]):
    if not root: return []
    return inorder_list(root.left) + [root.val] + inorder_list(root.right)

if __name__ == "__main__":
    t1 = TreeNode(1, TreeNode(3, TreeNode(5), None), TreeNode(2))
    t2 = TreeNode(2, TreeNode(1, None, TreeNode(4)), TreeNode(3, None, TreeNode(7)))
    merged = merge_trees(t1, t2)
    print(inorder_list(merged))  # [5, 4, 4, 3, 5, 7]
    print(inorder_list(merge_trees(TreeNode(1), None)))  # [1]
    print(merge_trees(None, None))  # None
