#!/usr/bin/env python3
"""
106. 从中序与后序遍历序列构造二叉树
"""
from typing import List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree_in_post(inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
    if not postorder: return None
    root = TreeNode(postorder[-1])
    idx = inorder.index(postorder[-1])
    root.left  = build_tree_in_post(inorder[:idx], postorder[:idx])
    root.right = build_tree_in_post(inorder[idx+1:], postorder[idx:-1])
    return root

def inorder_list(root: Optional[TreeNode]) -> List[int]:
    if not root: return []
    return inorder_list(root.left) + [root.val] + inorder_list(root.right)

if __name__ == "__main__":
    inorder1  = [9, 3, 15, 20, 7]
    postorder1 = [9, 15, 7, 20, 3]
    root1 = build_tree_in_post(inorder1, postorder1)
    print(inorder_list(root1))  # [9, 3, 15, 20, 7]
    print(inorder_list(build_tree_in_post([1], [1])))  # [1]
    print(build_tree_in_post([], []))  # None
