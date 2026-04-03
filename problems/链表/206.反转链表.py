#!/usr/bin/env python3
"""
206. 反转链表 (Reverse Linked List)
题目: 给你单链表的头节点 head，请你反转链表，并返回反转后的链表。
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverse_list(head: ListNode) -> ListNode:
    prev = None
    cur = head
    while cur:
        next_node = cur.next
        cur.next = prev
        prev = cur
        cur = next_node
    return prev

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
    # 测试用例1: 1->2->3->4->5 反转为 5->4->3->2->1
    head1 = list_to_linkedlist([1, 2, 3, 4, 5])
    result1 = reverse_list(head1)
    print("测试1 - 反转 [1,2,3,4,5]:")
    print(f"  输出: {linkedlist_to_list(result1)}")  # [5, 4, 3, 2, 1]

    # 测试用例2: 1->2 反转为 2->1
    head2 = list_to_linkedlist([1, 2])
    result2 = reverse_list(head2)
    print("\n测试2 - 反转 [1,2]:")
    print(f"  输出: {linkedlist_to_list(result2)}")  # [2, 1]

    # 测试用例3: 单节点 [] 反转后仍为 []
    head3 = list_to_linkedlist([1])
    result3 = reverse_list(head3)
    print("\n测试3 - 反转 [1]:")
    print(f"  输出: {linkedlist_to_list(result3)}")  # [1]
