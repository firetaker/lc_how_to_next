#!/usr/bin/env python3
"""
LeetCode #146: LRU 缓存
题目: 实现 LRU（最近最少使用）缓存，支持 get 和 put 操作，
      要求两操作均为 O(1)。
解法: 哈希表 + 双向链表 - 哈希表提供 O(1) 的键查找，
      双向链表维护访问顺序（头部最新，尾部最旧）。
      get：将节点移到头部；put：新节点插入头部，删除尾部（满时）。
      时间 O(1)，空间 O(capacity)。
"""


class DLinkedNode:
    def __init__(self, key=0, val=0):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None


class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}  # key -> DLinkedNode
        # 虚拟头尾节点简化操作
        self.head = DLinkedNode()
        self.tail = DLinkedNode()
        self.head.next = self.tail
        self.tail.prev = self.head

    def _remove(self, node: DLinkedNode):
        """从链表中移除节点"""
        node.prev.next = node.next
        node.next.prev = node.prev

    def _add_to_head(self, node: DLinkedNode):
        """插入到头节点之后（最新位置）"""
        node.next = self.head.next
        node.prev = self.head
        self.head.next.prev = node
        self.head.next = node

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        node = self.cache[key]
        self._remove(node)
        self._add_to_head(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self._remove(self.cache[key])
        node = DLinkedNode(key, value)
        self.cache[key] = node
        self._add_to_head(node)
        if len(self.cache) > self.capacity:
            # 删除最旧的（tail.prev）
            lru = self.tail.prev
            self._remove(lru)
            del self.cache[lru.key]


if __name__ == "__main__":
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    print(cache.get(1))  # 1
    cache.put(3, 3)      # 淘汰 key=2
    print(cache.get(2))  # -1
    cache.put(4, 4)      # 淘汰 key=1
    print(cache.get(1))  # -1
    print(cache.get(3))  # 3
    print(cache.get(4))  # 4
