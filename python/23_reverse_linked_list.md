# 反转链表（LeetCode #206）

## 题目描述

> 反转单链表，返回新链表的头节点。

**示例：**
- 输入：`1→2→3→4→5` → 输出：`5→4→3→2→1`

---

## 梯度分析

### 🔵 第一层：递归

```python
if not head or not head.next: return head
new_head = reverseList(head.next)
head.next.next = head
head.next = None
return new_head
```

### 🟢 第二层：头插法迭代 O(1) 空间

**核心洞察：** 遍历原链表，将每个节点以**头插法**插入新链表——新链表的节点顺序正好是原链表的逆序。

```python
prev = None
cur = head
while cur:
    nxt = cur.next   # 保存下一个
    cur.next = prev  # 反向指向前一个
    prev = cur       # prev 前移
    cur = nxt        # cur 前移
return prev  # prev 即新链表头
```

**图解 `1→2→3→4`：**

```
初始: prev=None, cur=1

步骤1: cur=1, nxt=2 → 1→None, prev=1, cur=2
       1→None

步骤2: cur=2, nxt=3 → 2→1→None, prev=2, cur=3
       2→1→None

步骤3: cur=3, nxt=4 → 3→2→1→None, prev=3, cur=4
       3→2→1→None

步骤4: cur=4, nxt=None → 4→3→2→1→None, prev=4, cur=None

结果: 4→3→2→1 ✅
```

**复杂度：**
- 时间：O(n)
- 空间：O(1)

---

## 破题总结

> **头插法迭代：遍历原链表，将每个节点插入新链表头部——每次把当前节点插到新链表最前面，遍历完即得到逆序链表。**
