#!/usr/bin/env python3
"""
LeetCode #21: 合并两个有序链表
题目: 将两个升序链表合并为一个升序链表。
解法: 迭代尾插法 / 递归 - 迭代：维护一个 dummy 头节点，
      比较两链表头部，较小的尾插到结果链表。时间 O(n+m)，空间 O(1)。
"""


class ListNode:
    def __init__(self, x=0, next=None):
        self.val = x
        self.next = next


def mergeTwoLists(l1: ListNode, l2: ListNode) -> ListNode:
    """
    迭代尾插法: dummy 简化边界处理，遍历两链表，尾插较小节点。
    """
    dummy = ListNode(0)
    cur = dummy
    while l1 and l2:
        if l1.val <= l2.val:
            cur.next = l1
            l1 = l1.next
        else:
            cur.next = l2
            l2 = l2.next
        cur = cur.next
    cur.next = l1 or l2
    return dummy.next


def mergeTwoLists_recursive(l1: ListNode, l2: ListNode) -> ListNode:
    """递归版"""
    if not l1: return l2
    if not l2: return l1
    if l1.val <= l2.val:
        l1.next = mergeTwoLists_recursive(l1.next, l2)
        return l1
    else:
        l2.next = mergeTwoLists_recursive(l1, l2.next)
        return l2


if __name__ == "__main__":
    # 1->2->4, 1->3->4
    a1 = ListNode(1); a2 = ListNode(2); a3 = ListNode(4)
    b1 = ListNode(1); b2 = ListNode(3); b3 = ListNode(4)
    a1.next = a2; a2.next = a3
    b1.next = b2; b2.next = b3
    res = mergeTwoLists(a1, b1)
    vals = []
    while res:
        vals.append(res.val)
        res = res.next
    print(vals)  # [1, 1, 2, 3, 4, 4]
