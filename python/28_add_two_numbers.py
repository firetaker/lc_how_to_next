#!/usr/bin/env python3
"""
LeetCode #2: 两数相加
题目: 给出两个非空链表，表示两个非负整数。每位数字逆序存储，返回相加结果。
解法: 递归（从低位到高位） / 迭代 - 从链表头部开始逐位相加，
      维护进位 carry = (l1.val + l2.val + carry) // 10，
      新节点值 = (l1.val + l2.val + carry) % 10。
      时间 O(max(n,m))，空间 O(max(n,m))。
"""


class ListNode:
    def __init__(self, x=0, next=None):
        self.val = x
        self.next = next


def addTwoNumbers(l1: ListNode, l2: ListNode, carry: int = 0) -> ListNode:
    """
    递归: 每层处理一个节点的三数之和（l1.val + l2.val + carry）。
    """
    if not l1 and not l2 and carry == 0:
        return None
    total = carry
    if l1: total += l1.val
    if l2: total += l2.val
    node = ListNode(total % 10)
    node.next = addTwoNumbers(
        l1.next if l1 else None,
        l2.next if l2 else None,
        total // 10
    )
    return node


def addTwoNumbers_iterative(l1: ListNode, l2: ListNode) -> ListNode:
    """迭代版"""
    dummy = ListNode(0)
    cur = dummy
    carry = 0
    while l1 or l2 or carry:
        total = carry
        if l1: total += l1.val; l1 = l1.next
        if l2: total += l2.val; l2 = l2.next
        cur.next = ListNode(total % 10)
        cur = cur.next
        carry = total // 10
    return dummy.next


if __name__ == "__main__":
    # 2->4->3 + 5->4->6 = 7->0->8 (342 + 465 = 807)
    a = ListNode(2); a.next = ListNode(4); a.next.next = ListNode(3)
    b = ListNode(5); b.next = ListNode(4); b.next.next = ListNode(6)
    res = addTwoNumbers(a, b)
    vals = []
    while res:
        vals.append(res.val)
        res = res.next
    print(vals)  # [7, 0, 8]
