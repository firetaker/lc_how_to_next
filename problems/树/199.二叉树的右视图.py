#!/usr/bin/env python3
"""
199. 二叉树的右视图
"""
from typing import List, Optional
from collections import deque
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def right_side_view(root: Optional[TreeNode]) -> List[int]:
    if not root: return []
    result = []
    queue = deque([root])
    while queue:
        size = len(queue)
        for i in range(size):
            node = queue.popleft()
            if i == size - 1:
                result.append(node.val)
            if node.left:  queue.append(node.left)
            if node.right: queue.append(node.right)
    return result

if __name__ == "__main__":
    root1 = TreeNode(1, TreeNode(2, None, TreeNode(5)), TreeNode(3))
    print(right_side_view(root1))  # [1, 3, 5]
    print(right_side_view(TreeNode(1)))  # [1]
    print(right_side_view(None))  # []
