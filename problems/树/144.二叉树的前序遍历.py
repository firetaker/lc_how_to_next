#!/usr/bin/env python3
"""
144. 二叉树的前序遍历
"""
from typing import List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def preorder_traversal(root: Optional[TreeNode]) -> List[int]:
    result = []
    stack = [root]
    while stack:
        node = stack.pop()
        if node:
            result.append(node.val)
            stack.append(node.right)
            stack.append(node.left)
    return result

if __name__ == "__main__":
    root1 = TreeNode(1, None, TreeNode(2, TreeNode(3), None))
    print(preorder_traversal(root1))  # [1, 2, 3]
    print(preorder_traversal(TreeNode(1)))  # [1]
    print(preorder_traversal(None))  # []
