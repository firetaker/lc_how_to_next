#!/usr/bin/env python3
"""
LeetCode #138: 随机链表的复制
题目: 给定链表，每个节点有 next 和 random 指针，复制整个链表。
解法: 节点后插入复制节点 + 分离 - 三步：
      1. 在原链表每个节点后插入复制节点（random 暂未设置）
      2. 遍历设置复制节点的 random 指针（copy.random = origin.random.next）
      3. 分离两个链表
      时间 O(n)，空间 O(1)（不计结果空间）。
"""


class Node:
    def __init__(self, x, next=None, random=None):
        self.val = x
        self.next = next
        self.random = random


def copyRandomList(head: Node) -> Node:
    """
    三步复制法:
    1. 插入复制节点：origin.next = copy
    2. 设置复制节点的 random：copy.random = origin.random.next
    3. 分离：origin.next = copy.next, copy.next = origin.next.next
    """
    if not head:
        return None
    # Step 1: 插入复制节点
    cur = head
    while cur:
        copy = Node(cur.val)
        copy.next = cur.next
        cur.next = copy
        cur = copy.next
    # Step 2: 设置 random 指针
    cur = head
    while cur:
        if cur.random:
            cur.next.random = cur.random.next
        cur = cur.next.next
    # Step 3: 分离
    cur = head
    dummy = head.next
    while cur:
        copy = cur.next
        cur.next = copy.next
        if copy.next:
            copy.next = copy.next.next
        cur = cur.next
    return dummy


if __name__ == "__main__":
    # 测试：7 -> 13 -> 11 -> 10 -> 1，随机指针
    n1 = Node(7); n2 = Node(13); n3 = Node(11); n4 = Node(10); n5 = Node(1)
    n1.next = n2; n2.next = n3; n3.next = n4; n4.next = n5
    n1.random = None; n2.random = n1; n3.random = n5; n4.random = n3; n5.random = n1
    copied = copyRandomList(n1)
    print(copied.val, copied.next.val)  # 7, 13
