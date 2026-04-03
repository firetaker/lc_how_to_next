#!/usr/bin/env python3
"""
LeetCode #148: 排序链表
题目: 将链表升序排列，要求 O(n log n) 时间，O(1) 空间。
解法: 归并排序（分治） - 用快慢指针找链表中点，分成两半递归排序，
      最后合并两个有序链表。链表的归并排序天然满足 O(1) 空间要求。
      时间 O(n log n)，空间 O(log n)（递归栈）。
"""


class ListNode:
    def __init__(self, x=0, next=None):
        self.val = x
        self.next = next


def sortList(head: ListNode) -> ListNode:
    """
    归并排序:
    1. 快慢指针找中点断开链表
    2. 递归排序左右两半
    3. 合并两个有序链表
    """
    if not head or not head.next:
        return head
    # 找中点（断开）
    slow = fast = head
    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next
    mid = slow.next
    slow.next = None
    # 递归排序
    left = sortList(head)
    right = sortList(mid)
    # 合并
    return mergeTwoLists(left, right)


def mergeTwoLists(l1: ListNode, l2: ListNode) -> ListNode:
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


if __name__ == "__main__":
    # -1->5->3->4->0
    nodes = [ListNode(x) for x in [-1, 5, 3, 4, 0]]
    for i in range(4): nodes[i].next = nodes[i+1]
    res = sortList(nodes[0])
    vals = []
    while res:
        vals.append(res.val)
        res = res.next
    print(vals)  # [-1, 0, 3, 4, 5]
