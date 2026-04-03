#!/usr/bin/env python3
"""
142. 环形链表 II (Linked List Cycle II)
题目: 给定一个链表，返回链表开始入环的第一个节点。如果链表无环，则返回 null。
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def detect_cycle(head: ListNode) -> ListNode:
    if not head or not head.next:
        return None
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            # 找到相遇点，从头节点和相遇点同时出发，再次相遇即为入环点
            slow2 = head
            while slow != slow2:
                slow = slow.next
                slow2 = slow2.next
            return slow
    return None

def list_to_linkedlist_with_cycle(lst, cycle_pos):
    if not lst:
        return None, None
    nodes = [ListNode(val) for val in lst]
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    if cycle_pos != -1 and cycle_pos < len(nodes):
        nodes[-1].next = nodes[cycle_pos]
    return nodes[0], nodes[cycle_pos] if cycle_pos != -1 else None

if __name__ == "__main__":
    # 测试用例1: 3->2->0->-4, 尾部连接到索引1 (值为2)
    head1, expected1 = list_to_linkedlist_with_cycle([3, 2, 0, -4], 1)
    result1 = detect_cycle(head1)
    print("测试1 - 链表 [3,2,0,-4] 入环点在索引1:")
    print(f"  预期入环节点值: {expected1.val if expected1 else None}")
    print(f"  输出: {result1.val if result1 else None}")

    # 测试用例2: 1->2, 尾部连接到头节点 (索引0)
    head2, expected2 = list_to_linkedlist_with_cycle([1, 2], 0)
    result2 = detect_cycle(head2)
    print("\n测试2 - 链表 [1,2] 入环点在头节点:")
    print(f"  预期入环节点值: {expected2.val if expected2 else None}")
    print(f"  输出: {result2.val if result2 else None}")

    # 测试用例3: 1 无环
    head3, _ = list_to_linkedlist_with_cycle([1], -1)
    result3 = detect_cycle(head3)
    print("\n测试3 - 链表 [1] 无环:")
    print(f"  输出: {result3}")  # None
