#!/usr/bin/env python3
"""
513. 找树左下角的值
"""
from typing import Optional
from collections import deque
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def find_bottom_left_value(root: Optional[TreeNode]) -> int:
    queue = deque([root])
    leftmost = root.val
    while queue:
        node = queue.popleft()
        leftmost = node.val
        if node.right: queue.append(node.right)
        if node.left: queue.append(node.left)
    return leftmost

if __name__ == "__main__":
    root1 = TreeNode(2, TreeNode(1), TreeNode(3))
    print(find_bottom_left_value(root1))  # 1
    root2 = TreeNode(1, TreeNode(2, TreeNode(4), None), TreeNode(3, TreeNode(6), TreeNode(7, TreeNode(9), None)))
    print(find_bottom_left_value(root2))  # 9
    print(find_bottom_left_value(TreeNode(1)))  # 1
