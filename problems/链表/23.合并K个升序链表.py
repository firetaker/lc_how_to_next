#!/usr/bin/env python3
"""
23. 合并K个升序链表 (Merge K Sorted Lists)
题目: 给你一个链表数组，每个链表都已经按升序排列。请你将所有链表合并成一个升序链表并返回。
"""

import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def merge_k_lists(lists) -> ListNode:
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

def list_to_linkedlist(lst):
    dummy = ListNode(0)
    cur = dummy
    for val in lst:
        cur.next = ListNode(val)
        cur = cur.next
    return dummy.next

def linkedlist_to_list(node):
    result = []
    while node:
        result.append(node.val)
        node = node.next
    return result

if __name__ == "__main__":
    # 测试用例1: [[1,4,5],[1,3,4],[2,6]] 合并为 [1,1,2,3,4,4,5,6]
    lists = [
        list_to_linkedlist([1, 4, 5]),
        list_to_linkedlist([1, 3, 4]),
        list_to_linkedlist([2, 6])
    ]
    result = merge_k_lists(lists)
    print("测试1 - 合并 [[1,4,5],[1,3,4],[2,6]]:")
    print(f"  输出: {linkedlist_to_list(result)}")  # [1, 1, 2, 3, 4, 4, 5, 6]

    # 测试用例2: [[], [1]] 合并为 [1]
    lists = [None, list_to_linkedlist([1])]
    result = merge_k_lists(lists)
    print("\n测试2 - 合并 [[], [1]]:")
    print(f"  输出: {linkedlist_to_list(result)}")  # [1]

    # 测试用例3: [[1,2,3],[4,5,6]] 合并为 [1,2,3,4,5,6]
    lists = [
        list_to_linkedlist([1, 2, 3]),
        list_to_linkedlist([4, 5, 6])
    ]
    result = merge_k_lists(lists)
    print("\n测试3 - 合并 [[1,2,3],[4,5,6]]:")
    print(f"  输出: {linkedlist_to_list(result)}")  # [1, 2, 3, 4, 5, 6]
