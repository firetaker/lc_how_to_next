#!/usr/bin/env python3
"""
19. 删除链表的倒数第N个节点 (Remove Nth Node From End)
题目: 给你一个链表，删除链表的倒数第 n 个节点，并且返回链表的头节点。
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def remove_nth_from_end(head: ListNode, n: int) -> ListNode:
    dummy = ListNode(0)
    dummy.next = head
    fast = slow = dummy
    for _ in range(n + 1):
        fast = fast.next
    while fast:
        slow = slow.next
        fast = fast.next
    slow.next = slow.next.next
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
    # 测试用例1: [1,2,3,4,5] 删除倒数第2个节点 (值为4) -> [1,2,3,5]
    head1 = list_to_linkedlist([1, 2, 3, 4, 5])
    result1 = remove_nth_from_end(head1, 2)
    print("测试1 - [1,2,3,4,5] 删除倒数第2个节点:")
    print(f"  输出: {linkedlist_to_list(result1)}")  # [1, 2, 3, 5]

    # 测试用例2: [1] 删除倒数第1个节点 -> []
    head2 = list_to_linkedlist([1])
    result2 = remove_nth_from_end(head2, 1)
    print("\n测试2 - [1] 删除倒数第1个节点:")
    print(f"  输出: {linkedlist_to_list(result2)}")  # []

    # 测试用例3: [1,2] 删除倒数第1个节点 (值为2) -> [1]
    head3 = list_to_linkedlist([1, 2])
    result3 = remove_nth_from_end(head3, 1)
    print("\n测试3 - [1,2] 删除倒数第1个节点:")
    print(f"  输出: {linkedlist_to_list(result3)}")  # [1]
