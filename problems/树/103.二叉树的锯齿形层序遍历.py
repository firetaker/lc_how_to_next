#!/usr/bin/env python3
"""
103. 二叉树的锯齿形层序遍历
"""
from typing import List, Optional
from collections import deque
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def zigzag_level_order(root: Optional[TreeNode]) -> List[List[int]]:
    if not root: return []
    result = []
    queue = deque([root])
    reverse = False
    while queue:
        level = []
        for _ in range(len(queue)):
            node = queue.popleft()
            level.append(node.val)
            if node.left:  queue.append(node.left)
            if node.right: queue.append(node.right)
        if reverse: level.reverse()
        result.append(level)
        reverse = not reverse
    return result

if __name__ == "__main__":
    root1 = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(zigzag_level_order(root1))  # [[3], [20, 9], [15, 7]]
    print(zigzag_level_order(TreeNode(1)))  # [[1]]
    print(zigzag_level_order(None))  # []
