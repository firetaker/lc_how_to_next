#!/usr/bin/env python3
"""
LeetCode #19: 删除链表的倒数第 N 个节点
题目: 给定链表和整数 n，删除倒数第 n 个节点，返回头节点。
解法: 前后指针（距离差） - 让快指针先走 n+1 步，然后快慢同速前进，
      当快指针到达尾部时，慢指针的下一个就是待删除节点。
      时间 O(n)，空间 O(1)。
"""


class ListNode:
    def __init__(self, x=0, next=None):
        self.val = x
        self.next = next


def removeNthFromEnd(head: ListNode, n: int) -> ListNode:
    """
    前后指针: fast 先走 n+1 步，然后 fast 和 slow 同时前进。
    当 fast 到达末尾时，slow.next 即待删除节点。
    """
    dummy = ListNode(0, head)
    fast = slow = dummy
    for _ in range(n + 1):
        fast = fast.next
    while fast:
        fast = fast.next
        slow = slow.next
    slow.next = slow.next.next
    return dummy.next


if __name__ == "__main__":
    # 1->2->3->4->5, n=2 → 1->2->3->5
    nodes = [ListNode(i) for i in range(1, 6)]
    for i in range(4): nodes[i].next = nodes[i+1]
    res = removeNthFromEnd(nodes[0], 2)
    vals = []
    while res:
        vals.append(res.val)
        res = res.next
    print(vals)  # [1, 2, 3, 5]
