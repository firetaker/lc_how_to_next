#!/usr/bin/env python3
"""
572. 另一棵树的子树
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_subtree(root: Optional[TreeNode], sub_root: Optional[TreeNode]) -> bool:
    if not root: return False
    def is_same(t1: Optional[TreeNode], t2: Optional[TreeNode]) -> bool:
        if not t1 and not t2: return True
        if not t1 or not t2: return False
        return t1.val == t2.val and is_same(t1.left, t2.left) and is_same(t1.right, t2.right)
    if is_same(root, sub_root): return True
    return is_subtree(root.left, sub_root) or is_subtree(root.right, sub_root)

if __name__ == "__main__":
    root = TreeNode(3, TreeNode(4, TreeNode(1), TreeNode(2)), TreeNode(5))
    sub = TreeNode(4, TreeNode(1), TreeNode(2))
    print(is_subtree(root, sub))  # True
    sub2 = TreeNode(3, TreeNode(1), TreeNode(2))
    print(is_subtree(root, sub2))  # False
    print(is_subtree(None, None))  # False
