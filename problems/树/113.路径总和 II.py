#!/usr/bin/env python3
"""
113. 路径总和 II
"""
from typing import List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def path_sum(root: Optional[TreeNode], target_sum: int) -> List[List[int]]:
    result = []
    path = []
    def dfs(node: Optional[TreeNode], remaining: int):
        if not node: return
        path.append(node.val)
        if not node.left and not node.right and remaining == node.val:
            result.append(path[:])
        dfs(node.left, remaining - node.val)
        dfs(node.right, remaining - node.val)
        path.pop()
    dfs(root, target_sum)
    return result

if __name__ == "__main__":
    root1 = TreeNode(5, TreeNode(4, TreeNode(11, TreeNode(7), TreeNode(2)), None),
                    TreeNode(8, TreeNode(13), TreeNode(4, None, TreeNode(1))))
    print(path_sum(root1, 22))  # [[5,4,11,2], [5,8,4,1]]
    print(path_sum(TreeNode(1), 1))  # [[1]]
    print(path_sum(None, 0))  # []
