#!/usr/bin/env python3
"""
109. 有序链表转换二叉搜索树
"""
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def sorted_list_to_bst(head: Optional[ListNode]) -> Optional[TreeNode]:
    if not head: return None
    if not head.next: return TreeNode(head.val)
    slow = fast = head
    prev = None
    while fast and fast.next:
        prev = slow
        slow = slow.next
        fast = fast.next.next
    root = TreeNode(slow.val)
    if prev:
        prev.next = None
        root.left = sorted_list_to_bst(head)
    root.right = sorted_list_to_bst(slow.next)
    return root

if __name__ == "__main__":
    # 构建链表: -10 -> -3 -> 0 -> 5 -> 9
    head1 = ListNode(-10, ListNode(-3, ListNode(0, ListNode(5, ListNode(9)))))
    root1 = sorted_list_to_bst(head1)
    print(root1.val)  # 0
    print(sorted_list_to_bst(None))  # None
