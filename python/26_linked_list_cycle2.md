# 环形链表 II（LeetCode #142）

## 题目描述

> 返回链表入环的第一个节点，若无环返回 None。

---

## 梯度分析

### 🔵 第一层：哈希集合

遍历链表，将节点加入集合，首次遇到已在集合中的节点即为入环点。O(n) 时间，O(n) 空间。

---

### 🟢 第二层：Floyd 判圈两步法 O(n) / O(1)

**两步走：**
1. **快慢指针相遇**：证明有环
2. **找入环点**：将一个指针重置到头，两个指针同速前进，再次相遇点即为入环点

**数学证明：**
```
设：非环部分长度为 a，入环点到相遇点长度为 b，环周长为 c
快指针走的距离 = 2 × 慢指针走的距离
(a + b + mc) = 2 × (a + b)
→ a + b = mc
→ a = (m-1)c + (c - b)
```
因此，从 head 走 a 步和从相遇点走 a 步，会同时到达入环点。

```python
# Step 1: 找相遇点
slow = fast = head
while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
    if slow == fast: break
if not fast or not fast.next: return None

# Step 2: 找入环点
slow2 = head
while slow != slow2:
    slow = slow.next
    slow2 = slow2.next
return slow
```

**图解：**

```
链表: 3→2→0→4→2（回到2）
      ↑____↓

Step1: 快慢指针在节点 2 相遇
Step2: slow2 从 head 出发，slow 从相遇点出发，同速前进
       slow2: 3→2 (相遇)
       slow:  2→0→4→2
       相遇点 = 节点 2 = 入环点 ✅
```

**复杂度：**
- 时间：O(n)
- 空间：O(1)

---

## 破题总结

> **Floyd 判圈两步法：快慢指针相遇证明有环，头指针和慢指针同速前进再次相遇即为入环点——数学推导 a=(m-1)c+(c-b) 保证相遇位置正确。**
