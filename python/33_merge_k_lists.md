# 合并 K 个升序链表（LeetCode #23）

## 题目描述

> 合并 K 个升序链表为一个升序链表。

**示例：**
- `[1→4→5]`, `[1→3→4]`, `[2→6]` → `1→1→2→3→4→4→5→6`

---

## 梯度分析

### 🔵 第一层：两两合并 O(kN)

依次合并 K-1 次两个有序链表。总 O(k × N)，其中 N 为总节点数。

---

### 🟢 第二层：最小堆（优先队列）O(N log k)

**核心洞察：** 维护一个大小为 k 的最小堆，每次弹出堆顶（当前所有链表的最小头节点），将其接入结果链表，并将该链表的下一个节点入堆。

```python
import heapq

heap = []
for i, node in enumerate(lists):
    if node:
        heapq.heappush(heap, (node.val, i, node))  # (val, index, node)

dummy = ListNode(0)
cur = dummy
while heap:
    val, i, node = heapq.heappop(heap)
    cur.next = node
    cur = cur.next
    if node.next:
        heapq.heappush(heap, (node.next.val, i, node.next))
return dummy.next
```

**为什么要用 `(val, i, node)` 而不是 `(val, node)`？**
- Python 的 heapq 要求元素可比较，当 val 相同时会比较第二个元素
- 用 index 作为第二键避免节点比较报错

**图解：**

```
初始堆: [(1,0,1→4→5), (1,1,1→3→4), (2,2,2→6)]

弹出 (1,0,1→4→5) → result=1, 1→4→5 的下一个 4 入堆
堆: [(1,1,1→3→4), (2,2,2→6), (4,0,4→5)]

弹出 (1,1,1→3→4) → result=1→1, 下一个 3 入堆
堆: [(2,2,2→6), (3,1,3→4), (4,0,4→5)]

弹出 (2,2,2→6) → result=1→1→2, 下一个 6 入堆
...

最终: 1→1→2→3→4→4→5→6 ✅
```

**复杂度：**
- 时间：O(N log k)，每个节点入堆出堆各一次，每次 O(log k)
- 空间：O(k)，堆中最多存 k 个元素

---

## 破题总结

> **最小堆归并：K 个链表的头节点入堆，每次弹出堆顶接入结果，并将弹出节点的下一个节点入堆——始终保持堆顶为全局最小，K 路归并的经典方法。**
