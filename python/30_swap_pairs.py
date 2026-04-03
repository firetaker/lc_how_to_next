#!/usr/bin/env python3
"""
LeetCode #24: 两两交换链表中的节点
题目: 给定链表，每两个节点交换一次，返回新链表头。
解法: 迭代 - 维护 prev（已处理部分尾）、curr（下一个小节点）、
      next_pair（下下个小节点）。交换 curr 和 next_pair，然后重连。
      时间 O(n)，空间 O(1)。
"""


class ListNode:
    def __init__(self, x=0, next=None):
        self.val = x
        self.next = next


def swapPairs(head: ListNode) -> ListNode:
    """
    迭代三指针: prev 指向已处理完的尾节点，
    交换 curr 和 next_pair 两个节点。
    """
    dummy = ListNode(0, head)
    prev = dummy
    while prev.next and prev.next.next:
        curr = prev.next
        nxt_pair = prev.next.next
        # 交换 curr 和 nxt_pair
        curr.next = nxt_pair.next
        nxt_pair.next = curr
        prev.next = nxt_pair
        # prev 移到交换后的尾（curr）
        prev = curr
    return dummy.next


def swapPairs_recursive(head: ListNode) -> ListNode:
    """递归版"""
    if not head or not head.next:
        return head
    nxt = head.next
    head.next = swapPairs_recursive(nxt.next)
    nxt.next = head
    return nxt


if __name__ == "__main__":
    # 1->2->3->4
    nodes = [ListNode(i) for i in range(1, 5)]
    for i in range(3): nodes[i].next = nodes[i+1]
    res = swapPairs(nodes[0])
    vals = []
    while res:
        vals.append(res.val)
        res = res.next
    print(vals)  # [2, 1, 4, 3]
