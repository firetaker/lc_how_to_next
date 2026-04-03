#!/usr/bin/env python3
"""
116. 填充每个节点的下一个右侧节点指针
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def connect(root: Optional[TreeNode]) -> Optional[TreeNode]:
    if not root: return root
    if root.left:  root.left.next = root.right
    if root.next and root.right: root.right.next = root.next.left
    connect(root.left)
    connect(root.right)
    return root

if __name__ == "__main__":
    root = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)),
                        TreeNode(3, TreeNode(6), TreeNode(7)))
    connect(root)
    print(root.left.next.val)          # 3
    print(root.left.left.next.val)     # 5
    print(root.right.left.next.val)    # 7
    print(connect(None))  # None
