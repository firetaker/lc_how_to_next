#!/usr/bin/env python3
"""
LeetCode #234: 回文链表
题目: 判断链表是否是回文。
解法: 快慢指针找中点 + 反转后半链表 - 快指针走两步，慢指针走一步，
      找到链表中点后，反转后半部分，然后从两端向中间比较。
      时间 O(n)，空间 O(1)。
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def isPalindrome(head: ListNode) -> bool:
    """
    快慢指针找中点 + 反转后半部分:
    1. 找中点（奇数时归为后半部分第一个节点）
    2. 反转后半部分
    3. 比较前半和反转后的后半
    """
    if not head or not head.next:
        return True
    # 找中点：slow 最终在中点（或中点偏后）
    slow = fast = head
    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next
    # 反转后半部分
    mid = slow
    prev = None
    cur = mid.next
    while cur:
        nxt = cur.next
        cur.next = prev
        prev = cur
        cur = nxt
    mid.next = None  # 断开前后
    # 比较前半和反转后的后半
    p1, p2 = head, prev
    while p2:  # p2 为后半反转，长度 <= 前半
        if p1.val != p2.val:
            return False
        p1 = p1.next
        p2 = p2.next
    return True


if __name__ == "__main__":
    # 1->2->2->1
    n1 = ListNode(1); n2 = ListNode(2); n3 = ListNode(2); n4 = ListNode(1)
    n1.next = n2; n2.next = n3; n3.next = n4
    print(isPalindrome(n1))  # True
    n1.next = ListNode(2); n1.next.next = ListNode(1)  # 1->2->1
    print(isPalindrome(n1))  # True
