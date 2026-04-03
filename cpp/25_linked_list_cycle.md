# 环形链表（LeetCode #141）

## 题目描述

> 判断链表中是否存在环。

**示例：** `3→2→0→-4`，尾部连到节点 2 → `True`

---

## 梯度分析

### 🔵 第一层：哈希集合记录访问过的节点

O(n) 时间，O(n) 空间。

---

### 🟢 第二层：Floyd 快慢指针 O(n) / O(1)

```cpp
ListNode *slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;
}
return false;
```

**图解 `3→2→0→4→2（回到2）`：**

```
步1: slow=2, fast=0
步2: slow=4, fast=2
步3: slow=0, fast=4
步4: slow=2, fast=2 → 相遇 ✅
```

**复杂度：**
- 时间：O(n)
- 空间：O(1)

---

## 破题总结

> **快慢指针同速赛跑：快两步慢一步，若链表有环则必然在环内相遇——匀速追赶模型保证了 O(n) 时间 O(1) 空间。**
