#!/usr/bin/env python3
"""
234. 回文链表 (Palindrome Linked List)
题目: 给你一个单链表，请你判断该链表是否为回文链表。
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def is_palindrome(head: ListNode) -> bool:
    if not head or not head.next:
        return True
    # 找到链表的中点
    slow, fast = head, head
    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next
    # 反转后半部分链表
    prev, cur = None, slow.next
    while cur:
        next_node = cur.next
        cur.next = prev
        prev = cur
        cur = next_node
    # 比较前半部分和反转后的后半部分
    p1, p2 = head, prev
    while p2:
        if p1.val != p2.val:
            return False
        p1 = p1.next
        p2 = p2.next
    return True

def list_to_linkedlist(lst):
    dummy = ListNode(0)
    cur = dummy
    for val in lst:
        cur.next = ListNode(val)
        cur = cur.next
    return dummy.next

if __name__ == "__main__":
    # 测试用例1: 1->2 是回文链表
    head1 = list_to_linkedlist([1, 2])
    print("测试1 - [1,2] 是回文链表:")
    print(f"  输出: {is_palindrome(head1)}")  # False

    # 测试用例2: 1->2->2->1 是回文链表
    head2 = list_to_linkedlist([1, 2, 2, 1])
    print("\n测试2 - [1,2,2,1] 是回文链表:")
    print(f"  输出: {is_palindrome(head2)}")  # True

    # 测试用例3: 1->2->3->2->1 是回文链表
    head3 = list_to_linkedlist([1, 2, 3, 2, 1])
    print("\n测试3 - [1,2,3,2,1] 是回文链表:")
    print(f"  输出: {is_palindrome(head3)}")  # True
