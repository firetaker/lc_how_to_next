#!/usr/bin/env python3
"""
21. 合并两个有序链表 (Merge Two Sorted Lists)
题目: 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def merge_two_lists(l1: ListNode, l2: ListNode) -> ListNode:
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
    # 测试用例1: 1->2->4 和 1->3->4 合并为 1->1->2->3->4->4
    l1 = list_to_linkedlist([1, 2, 4])
    l2 = list_to_linkedlist([1, 3, 4])
    result = merge_two_lists(l1, l2)
    print("测试1 - 合并 [1,2,4] 和 [1,3,4]:")
    print(f"  输出: {linkedlist_to_list(result)}")  # [1, 1, 2, 3, 4, 4]

    # 测试用例2: 空链表和 0->1->2->3 合并为 0->1->2->3
    l1 = None
    l2 = list_to_linkedlist([0, 1, 2, 3])
    result = merge_two_lists(l1, l2)
    print("\n测试2 - 合并 [] 和 [0,1,2,3]:")
    print(f"  输出: {linkedlist_to_list(result)}")  # [0, 1, 2, 3]

    # 测试用例3: [] 和 [] 合并为 []
    l1 = None
    l2 = None
    result = merge_two_lists(l1, l2)
    print("\n测试3 - 合并 [] 和 []:")
    print(f"  输出: {linkedlist_to_list(result)}")  # []
