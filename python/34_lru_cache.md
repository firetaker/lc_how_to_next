# LRU 缓存（LeetCode #146）

## 题目描述

> 实现最近最少使用（LRU）缓存，支持 `get(key)` 和 `put(key, value)`，两操作均 O(1)。

---

## 梯度分析

### 🔵 第一层：哈希表 + 列表（按访问顺序）

哈希表存 key→value，列表维护访问顺序。每次 get/put 把元素移到列表最前，删除最旧时从列表末尾移除。get O(1)，put O(1) 但删除 O(n)。

---

### 🟢 第二层：哈希表 + 双向链表 O(1) / O(capacity)

**核心思想：**
- **哈希表**：key → 链表节点，实现 O(1) 查找
- **双向链表**：维护访问顺序，头部最新，尾部最旧

**get 操作的精髓：** 找到节点后，将其移到链表头部（标记为最新使用）。

**put 操作的精髓：** 新节点插入头部；若缓存满，删除链表尾部（最旧）并从哈希表移除。

```python
class LRUCache:
    def __init__(self, capacity):
        self.cap = capacity
        self.cache = {}  # key -> DLinkedNode
        self.head = DLinkedNode()  # dummy 头（最新）
        self.tail = DLinkedNode()  # dummy 尾（最旧）
        self.head.next = self.tail
        self.tail.prev = self.head

    def _remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def _add_to_head(self, node):
        node.next = self.head.next
        node.prev = self.head
        self.head.next.prev = node
        self.head.next = node

    def get(self, key):
        if key not in self.cache:
            return -1
        node = self.cache[key]
        self._remove(node)
        self._add_to_head(node)  # 移到最新
        return node.val

    def put(self, key, value):
        if key in self.cache:
            self._remove(self.cache[key])
        node = DLinkedNode(key, value)
        self.cache[key] = node
        self._add_to_head(node)
        if len(self.cache) > self.cap:
            lru = self.tail.prev  # 最旧的
            self._remove(lru)
            del self.cache[lru.key]
```

**图解 get("A") 后再 put("D", 4)：**

```
初始状态（容量=2）:
  head ↔ A(val=1) ↔ B(val=2) ↔ tail
  cache: {A:node_A, B:node_B}

get("A"):
  找到 A → _remove(A) → _add_to_head(A)
  head ↔ A(val=1) ↔ B(val=2) ↔ tail

put("D", 4):
  D 不在 cache → 新建 D
  _add_to_head(D)
  head ↔ D(val=4) ↔ A(val=1) ↔ B(val=2) ↔ tail
  缓存超过容量 → 删除 tail.prev = B
  head ↔ D ↔ A ↔ tail
```

**复杂度：**
- 时间：O(1)，哈希表查找 O(1)，链表插入/删除 O(1)
- 空间：O(capacity)

---

## 破题总结

> **哈希表提供 O(1) 查找，双向链表维护访问顺序（头最新尾最旧）。get 将节点移到头部，put 插入头部后删除尾部（满时）。两个数据结构各司其职，保证 O(1)。**
