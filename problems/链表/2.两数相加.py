#!/usr/bin/env python3
"""
2. 两数相加 (Add Two Numbers)
题目: 给你两个非空链表，表示两个非负整数。每个链表中的数字都是按照逆序存储的，
并且每个节点只能存储一位数字。将这两个数相加并返回一个新的链表。
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def add_two_numbers(l1: ListNode, l2: ListNode) -> ListNode:
    dummy = ListNode(0)
    cur = dummy
    carry = 0
    while l1 or l2 or carry:
        val1 = l1.val if l1 else 0
        val2 = l2.val if l2 else 0
        total = val1 + val2 + carry
        carry = total // 10
        cur.next = ListNode(total % 10)
        cur = cur.next
        l1 = l1.next if l1 else None
        l2 = l2.next if l2 else None
    return dummy.next

def list_to_linkedlist(lst):
    """将列表转换为链表"""
    dummy = ListNode(0)
    cur = dummy
    for val in lst:
        cur.next = ListNode(val)
        cur = cur.next
    return dummy.next

def linkedlist_to_list(node):
    """将链表转换为列表"""
    result = []
    while node:
        result.append(node.val)
        node = node.next
    return result

if __name__ == "__main__":
    # 测试用例1: 342 + 465 = 807 (链表: 2->4->3 + 5->6->4 = 7->0->8)
    l1 = list_to_linkedlist([2, 4, 3])
    l2 = list_to_linkedlist([5, 6, 4])
    result = add_two_numbers(l1, l2)
    print("测试1 - 342 + 465:")
    print(f"  输入: l1 = [2,4,3], l2 = [5,6,4]")
    print(f"  输出: {linkedlist_to_list(result)}")  # [7, 0, 8]

    # 测试用例2: 9999999 + 9999 = 10009998
    l1 = list_to_linkedlist([9, 9, 9, 9, 9, 9, 9])
    l2 = list_to_linkedlist([9, 9, 9, 9])
    result = add_two_numbers(l1, l2)
    print("\n测试2 - 9999999 + 9999:")
    print(f"  输入: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]")
    print(f"  输出: {linkedlist_to_list(result)}")  # [8, 9, 9, 9, 0, 0, 0, 1]

    # 测试用例3: 0 + 0 = 0
    l1 = list_to_linkedlist([0])
    l2 = list_to_linkedlist([0])
    result = add_two_numbers(l1, l2)
    print("\n测试3 - 0 + 0:")
    print(f"  输入: l1 = [0], l2 = [0]")
    print(f"  输出: {linkedlist_to_list(result)}")  # [0]
