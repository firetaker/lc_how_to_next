#!/usr/bin/env python3
"""
94. 二叉树的中序遍历
"""
from typing import List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def inorder_traversal(root: Optional[TreeNode]) -> List[int]:
    result = []
    stack = []
    cur = root
    while cur or stack:
        while cur:
            stack.append(cur)
            cur = cur.left
        cur = stack.pop()
        result.append(cur.val)
        cur = cur.right
    return result

if __name__ == "__main__":
    root1 = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))
    print(inorder_traversal(root1))  # [4, 2, 5, 1, 3]
    print(inorder_traversal(TreeNode(1)))  # [1]
    print(inorder_traversal(None))  # []
