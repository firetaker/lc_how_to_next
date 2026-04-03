#!/usr/bin/env python3
"""
235. 二叉搜索树的最近公共祖先
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def lowest_common_ancestor(root: Optional[TreeNode], p: TreeNode, q: TreeNode) -> Optional[TreeNode]:
    while root:
        if p.val < root.val and q.val < root.val:
            root = root.left
        elif p.val > root.val and q.val > root.val:
            root = root.right
        else:
            return root
    return root

if __name__ == "__main__":
    root = TreeNode(6, TreeNode(2, TreeNode(0), TreeNode(4, TreeNode(3), TreeNode(5))),
                    TreeNode(8, TreeNode(7), TreeNode(9)))
    p = root.left
    q = root.right
    print(lowest_common_ancestor(root, p, q).val)  # 6
    p2 = root.left
    q2 = root.left.right
    print(lowest_common_ancestor(root, p2, q2).val)  # 2
    print(lowest_common_ancestor(None, None, None))  # None
