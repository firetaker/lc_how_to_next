#!/usr/bin/env python3
"""
LeetCode #206: 反转链表
题目: 给定单链表，反转后返回新链表的头节点。
解法: 头插法 / 双指针迭代 - 遍历原链表，将每个节点以头插法方式插入新链表。
      也可用递归。时间 O(n)，空间 O(1)。
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def reverseList(head: ListNode) -> ListNode:
    """
    头插法: prev=None 为新链表头，cur 从 head 开始遍历，
    每次将 cur.next 指向 prev，然后 prev=cur, cur=next。
    """
    prev = None
    cur = head
    while cur:
        nxt = cur.next
        cur.next = prev
        prev = cur
        cur = nxt
    return prev


def reverseList_recursive(head: ListNode) -> ListNode:
    """递归版"""
    if not head or not head.next:
        return head
    new_head = reverseList_recursive(head.next)
    head.next.next = head
    head.next = None
    return new_head


if __name__ == "__main__":
    # 1->2->3->4->5
    nodes = [ListNode(i) for i in range(1, 6)]
    for i in range(4): nodes[i].next = nodes[i+1]
    rev = reverseList(nodes[0])
    vals = []
    while rev:
        vals.append(rev.val)
        rev = rev.next
    print(vals)  # [5, 4, 3, 2, 1]
