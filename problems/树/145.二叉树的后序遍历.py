#!/usr/bin/env python3
"""
145. 二叉树的后序遍历
"""
from typing import List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def postorder_traversal(root: Optional[TreeNode]) -> List[int]:
    result = []
    stack = []
    cur = root
    while cur or stack:
        while cur:
            stack.append((cur, False))
            cur = cur.left
        node, visited = stack.pop()
        if visited:
            result.append(node.val)
        else:
            stack.append((node, True))
            cur = node.right
    return result

if __name__ == "__main__":
    root1 = TreeNode(1, None, TreeNode(2, TreeNode(3), None))
    print(postorder_traversal(root1))  # [3, 2, 1]
    print(postorder_traversal(TreeNode(1)))  # [1]
    print(postorder_traversal(None))  # []
