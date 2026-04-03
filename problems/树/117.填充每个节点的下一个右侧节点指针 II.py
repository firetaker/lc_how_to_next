#!/usr/bin/env python3
"""
117. 填充每个节点的下一个右侧节点指针 II
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def connect(root: Optional[TreeNode]) -> Optional[TreeNode]:
    if not root: return root
    dummy = TreeNode(0)
    cur = dummy
    while root:
        if root.left:
            cur.next = root.left
            cur = cur.next
        if root.right:
            cur.next = root.right
            cur = cur.next
        root = root.next
        if not root:
            cur = dummy
            root = dummy.next
            dummy.next = None
    return dummy

if __name__ == "__main__":
    root = TreeNode(1, TreeNode(2, None, TreeNode(4)), TreeNode(3, TreeNode(5), None))
    result = connect(root)
    print(result.val)  # 1
    print(connect(None))  # None
