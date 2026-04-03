#!/usr/bin/env python3
"""
112. 路径总和
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def has_path_sum(root: Optional[TreeNode], target_sum: int) -> bool:
    if not root: return False
    if not root.left and not root.right: return root.val == target_sum
    return has_path_sum(root.left, target_sum - root.val) or            has_path_sum(root.right, target_sum - root.val)

if __name__ == "__main__":
    root1 = TreeNode(5, TreeNode(4, TreeNode(11, TreeNode(7), TreeNode(2)), None),
                    TreeNode(8, TreeNode(13), TreeNode(4, None, TreeNode(1))))
    print(has_path_sum(root1, 22))  # True
    print(has_path_sum(root1, 5))   # False
    print(has_path_sum(TreeNode(1), 1))  # True
    print(has_path_sum(TreeNode(1), 0))  # False
    print(has_path_sum(None, 0))  # False
