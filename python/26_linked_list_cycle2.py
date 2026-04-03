#!/usr/bin/env python3
"""
LeetCode #142: 环形链表 II
题目: 返回链表入环的第一个节点，若无环返回 None。
解etCode #142: 环形链表 II
解法: Floyd 判圈（快慢指针） - 第一步快慢指针相遇，证明有环；
      第二步将一个指针重置到头节点，两个指针同速前进，再次相遇的节点即为入环点。
      数学证明：设非环部分长度为 a，入环点到相遇点长度为 b，
      环长为 c。2(a+b) = a + b + nc → a = (n-1)c + (c-b)，
      故从 head 和相遇点同时出发，相遇点即为入环点。
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def detectCycle(head: ListNode) -> ListNode:
    """
    Floyd 判圈两步:
    1. 快慢指针找相遇点
    2. 头指针和慢指针同速前进，相遇点即入环节点
    """
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            # 找入环点
            slow2 = head
            while slow != slow2:
                slow = slow.next
                slow2 = slow2.next
            return slow
    return None


if __name__ == "__main__":
    # 3->2->0->-4，尾部连到节点2
    n3 = ListNode(3); n2 = ListNode(2); n0 = ListNode(0); n4 = ListNode(-4)
    n3.next = n2; n2.next = n0; n0.next = n4; n4.next = n2
    res = detectCycle(n3)
    print(res.val if res else None)  # 2
