#!/usr/bin/env python3
"""
LeetCode #141: 环形链表
题目: 判断链表中是否存在环。
解法: 快慢指针（Floyd 判圈） - 快指针每次走两步，慢指针每次走一步。
      若存在环，两者必然在环内相遇。时间 O(n)，空间 O(1)。
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def hasCycle(head: ListNode) -> bool:
    """
    快慢指针: fast 走两步，slow 走一步。
    若链表有环，fast 和 slow 必然在环内相遇。
    """
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False


if __name__ == "__main__":
    # 构建环: 1->2->3->4->2
    n1 = ListNode(1); n2 = ListNode(2); n3 = ListNode(3); n4 = ListNode(4)
    n1.next = n2; n2.next = n3; n3.next = n4; n4.next = n2
    print(hasCycle(n1))  # True
    # 无环
    n1.next = n2; n2.next = n3; n3.next = n4; n4.next = None
    print(hasCycle(n1))  # False
