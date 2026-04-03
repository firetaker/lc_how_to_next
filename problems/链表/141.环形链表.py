#!/usr/bin/env python3
"""
141. 环形链表 (Linked List Cycle)
题目: 给你一个链表的头节点 head，判断链表中是否有环。
如果链表中有某个节点可以通过连续跟随 next 指针再次到达，则称该链表是环形链表。
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def has_cycle(head: ListNode) -> bool:
    if not head or not head.next:
        return False
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False

def list_to_linkedlist_with_cycle(lst, cycle_pos):
    """将列表转换为链表，可选地在指定位置形成环"""
    if not lst:
        return None
    nodes = [ListNode(val) for val in lst]
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    if cycle_pos != -1 and cycle_pos < len(nodes):
        nodes[-1].next = nodes[cycle_pos]
    return nodes[0]

if __name__ == "__main__":
    # 测试用例1: 3->2->0->-4, 尾部连接到尾节点形成环
    head1 = list_to_linkedlist_with_cycle([3, 2, 0, -4], 1)
    print("测试1 - 链表 [3,2,0,-4] 形成环 (尾节点指向索引1):")
    print(f"  输出: {has_cycle(head1)}")  # True

    # 测试用例2: 1->2, 尾部连接到头节点形成环
    head2 = list_to_linkedlist_with_cycle([1, 2], 0)
    print("\n测试2 - 链表 [1,2] 形成环 (尾节点指向头节点):")
    print(f"  输出: {has_cycle(head2)}")  # True

    # 测试用例3: 1, 无环
    head3 = list_to_linkedlist_with_cycle([1], -1)
    print("\n测试3 - 链表 [1] 无环:")
    print(f"  输出: {has_cycle(head3)}")  # False
