#!/usr/bin/env python3
"""
LeetCode #23: 合并K个升序链表
题目: 给定 K 个升序链表，合并为一个升序链表。
解法: 最小堆（优先队列） - 维护大小为 K 的最小堆，
      初始将每个链表的头节点入堆，每次弹出最小节点并将其下一节点入堆。
      时间 O(N log K)，N 为总节点数，K 为链表数量。
"""


import heapq


class ListNode:
    def __init__(self, x=0, next=None):
        self.val = x
        self.next = next


def mergeKLists(lists: list[ListNode]) -> ListNode:
    """
    最小堆: heap 中存 (节点值, 索引, 节点) 以避免节点比较问题。
    """
    heap = []
    for i, node in enumerate(lists):
        if node:
            heapq.heappush(heap, (node.val, i, node))
    dummy = ListNode(0)
    cur = dummy
    while heap:
        val, i, node = heapq.heappop(heap)
        cur.next = node
        cur = cur.next
        if node.next:
            heapq.heappush(heap, (node.next.val, i, node.next))
    return dummy.next


if __name__ == "__main__":
    # [[1->4->5], [1->3->4], [2->6]]
    l1 = ListNode(1, ListNode(4, ListNode(5)))
    l2 = ListNode(1, ListNode(3, ListNode(4)))
    l3 = ListNode(2, ListNode(6))
    res = mergeKLists([l1, l2, l3])
    vals = []
    while res:
        vals.append(res.val)
        res = res.next
    print(vals)  # [1, 1, 2, 3, 4, 4, 5, 6]
