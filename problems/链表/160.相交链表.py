#!/usr/bin/env python3
"""
160. 相交链表 (Intersection of Two Linked Lists)
题目: 给你两个单链表的头节点 headA 和 headB，请你返回相交链表的头节点。
如果两个链表没有交点，返回 null。
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def get_intersection_node(headA: ListNode, headB: ListNode) -> ListNode:
    if not headA or not headB:
        return None
    pa, pb = headA, headB
    while pa != pb:
        pa = pa.next if pa else headB
        pb = pb.next if pb else headA
    return pa

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
    # 测试用例1: 相交于节点 8
    # A: 4->1->8->4->5, B: 5->0->1->8->4->5 (相交于 8)
    common = ListNode(8, ListNode(4, ListNode(5)))
    headA = ListNode(4, ListNode(1, common))
    headB = ListNode(5, ListNode(0, ListNode(1, common)))
    result = get_intersection_node(headA, headB)
    print("测试1 - 相交链表:")
    print(f"  输出: {result.val if result else None}")  # 8

    # 测试用例2: 不相交
    headC = list_to_linkedlist([1, 2, 3])
    headD = list_to_linkedlist([4, 5, 6])
    result2 = get_intersection_node(headC, headD)
    print("\n测试2 - 不相交链表:")
    print(f"  输出: {result2}")  # None

    # 测试用例3: 完全重合
    headE = list_to_linkedlist([1, 2, 3])
    result3 = get_intersection_node(headE, headE)
    print("\n测试3 - 完全重合链表:")
    print(f"  输出: {result3.val if result3 else None}")  # 1
