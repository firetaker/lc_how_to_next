# 反转链表（LeetCode #206）

## 题目描述

> 反转单链表，返回新链表头。

**示例：** `1→2→3→4→5` → `5→4→3→2→1`

---

## 梯度分析

### 🔵 第一层：递归

```cpp
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* new_head = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}
```

---

### 🟢 第二层：头插法迭代 O(1) 空间

```cpp
ListNode *prev = nullptr, *cur = head;
while (cur) {
    ListNode* nxt = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nxt;
}
return prev;
```

**图解 `1→2→3→4`：**

```
步骤1: cur=1 → 1→None, prev=1, cur=2
步骤2: cur=2 → 2→1→None, prev=2, cur=3
步骤3: cur=3 → 3→2→1→None, prev=3, cur=4
步骤4: cur=4 → 4→3→2→1→None, prev=4, cur=None
→ 4→3→2→1 ✅
```

**复杂度：**
- 时间：O(n)
- 空间：O(1)

---

## 破题总结

> **头插法迭代：遍历原链表，将每个节点以头插法插入新链表——每次把当前节点插到新链表最前面，遍历完即得到逆序链表。**
