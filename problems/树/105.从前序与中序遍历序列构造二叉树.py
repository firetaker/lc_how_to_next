#!/usr/bin/env python3
"""
105. 从前序与中序遍历序列构造二叉树
"""
from typing import List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree(preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
    if not preorder: return None
    root = TreeNode(preorder[0])
    idx = inorder.index(preorder[0])
    root.left  = build_tree(preorder[1:idx+1], inorder[:idx])
    root.right = build_tree(preorder[idx+1:], inorder[idx+1:])
    return root

def inorder_list(root: Optional[TreeNode]) -> List[int]:
    if not root: return []
    return inorder_list(root.left) + [root.val] + inorder_list(root.right)

if __name__ == "__main__":
    preorder1 = [3, 9, 20, 15, 7]
    inorder1  = [9, 3, 15, 20, 7]
    root1 = build_tree(preorder1, inorder1)
    print(inorder_list(root1))  # [9, 3, 15, 20, 7]
    print(inorder_list(build_tree([1], [1])))  # [1]
    print(build_tree([], []))  # None
