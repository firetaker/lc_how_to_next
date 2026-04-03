# 随机链表的复制（LeetCode #138）

## 题目描述

> 复制一个带 random 指针的链表，random 指向链表中任意节点或 None。

---

## 梯度分析

### 🔵 第一层：哈希表记录原节点→复制节点

遍历原链表，将每个节点及其复制节点存入哈希表。第二遍遍历设置 next 和 random。O(n) 时间，O(n) 空间。

---

### 🟢 第二层：三步原地复制 O(1) 额外空间（不计结果）

**三步走：**
1. **插入复制节点**：在原链表每个节点后插入一个复制节点（random 暂未设置）
2. **设置 random 指针**：遍历链表，`copy.random = origin.random.next`（copy 的 random 指向 origin.random 的下一个，即 copy 版的对应节点）
3. **分离两个链表**：交替提取出复制节点，恢复原链表

```python
# Step 1: 插入复制节点
cur = head
while cur:
    copy = Node(cur.val)
    copy.next = cur.next
    cur.next = copy
    cur = copy.next

# Step 2: 设置 random
cur = head
while cur:
    if cur.random:
        cur.next.random = cur.random.next
    cur = cur.next.next

# Step 3: 分离
dummy = head.next
cur = head
while cur:
    copy = cur.next
    cur.next = copy.next
    if copy.next:
        copy.next = copy.next.next
    cur = cur.next
return dummy
```

**图解：**

```
Step 1 插入后:
  1→1'→2→2'→3→3'→4→4'→5→5'
  (1' 是 1 的复制节点)

Step 2 设置 random (假设 1.random=3, 2.random=1, 3.random=5):
  1.next.random = 3.next = 3'
  2.next.random = 1.next = 1'
  3.next.random = 5.next = 5'
  ✅ 每个复制节点的 random 指向对应的复制节点

Step 3 分离:
  原链表: 1→2→3→4→5
  复制链表: 1'→2'→3'→4'→5' ✅
```

**复杂度：**
- 时间：O(n)
- 空间：O(1)（不计结果空间）

---

## 破题总结

> **三步原地复制：在原节点后插入复制节点 → 设置复制节点的 random 指针（copy.random = origin.random.next）→ 交替分离两个链表。插入时天然保证了复制节点和原节点的对应关系。**
