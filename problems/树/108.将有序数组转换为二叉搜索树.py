#!/usr/bin/env python3
"""
108. 将有序数组转换为二叉搜索树
"""
from typing import List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def sorted_array_to_bst(nums: List[int]) -> Optional[TreeNode]:
    if not nums: return None
    mid = len(nums) // 2
    root = TreeNode(nums[mid])
    root.left  = sorted_array_to_bst(nums[:mid])
    root.right = sorted_array_to_bst(nums[mid+1:])
    return root

def inorder_list(root: Optional[TreeNode]) -> List[int]:
    if not root: return []
    return inorder_list(root.left) + [root.val] + inorder_list(root.right)

if __name__ == "__main__":
    nums1 = [-10, -3, 0, 5, 9]
    root1 = sorted_array_to_bst(nums1)
    print(inorder_list(root1))  # [-10, -3, 0, 5, 9]
    print(inorder_list(sorted_array_to_bst([1, 3])))  # [1, 3]
    print(sorted_array_to_bst([]))  # None
