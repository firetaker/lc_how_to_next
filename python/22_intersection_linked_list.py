#!/usr/bin/env python3
"""
LeetCode #160: 相交链表
题目: 给定两个链表的头节点，判断它们是否相交，返回相交的第一个节点。
解法: 双指针切换法 - 指针 a 走完链表 A 后切换到链表 B，
      指针 b 走完链表 B 后切换到链表 A。若相交，两者必然在
      「走过的总长度相等」时相遇。时间 O(n+m)，空间 O(1)。
      原理：a + (A→B) = b + (B→A)，消除尾部差距后必相遇。
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def getIntersectionNode(headA: ListNode, headB: ListNode) -> ListNode:
    """
    双指针切换: a 走完 A 切 B，b 走完 B 切 A。
    相交点即相遇点（不为 None）。
    """
    if not headA or not headB:
        return None
    a, b = headA, headB
    while a != b:
        a = a.next if a.next else headB
        b = b.next if b.next else headA
    return a  # 或 b，相交点或 None


if __name__ == "__main__":
    # 构建相交链表: 1->2->3->4
    n1 = ListNode(1); n2 = ListNode(2); n3 = ListNode(3); n4 = ListNode(4)
    n1.next = n2; n2.next = n3; n3.next = n4
    # A: 1->2->3->4, B: 5->3->4
    b1 = ListNode(5); b1.next = n3
    res = getIntersectionNode(n1, b1)
    print(res.val if res else None)  # 3
