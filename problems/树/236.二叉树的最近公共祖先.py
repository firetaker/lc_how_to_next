#!/usr/bin/env python3
"""
236. 二叉树的最近公共祖先
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def lowest_common_ancestor(root: Optional[TreeNode], p: TreeNode, q: TreeNode) -> Optional[TreeNode]:
    if not root or root == p or root == q: return root
    left  = lowest_common_ancestor(root.left, p, q)
    right = lowest_common_ancestor(root.right, p, q)
    if left and right: return root
    return left or right

if __name__ == "__main__":
    root = TreeNode(3, TreeNode(5, TreeNode(6), TreeNode(2, TreeNode(7), TreeNode(4))),
                    TreeNode(1, TreeNode(0), TreeNode(8)))
    p = root.left
    q = root.left.right.right
    print(lowest_common_ancestor(root, p, q).val)  # 5
    p2 = root.left.right
    q2 = root.right
    print(lowest_common_ancestor(root, p2, q2).val)  # 3
    print(lowest_common_ancestor(None, None, None))  # None
