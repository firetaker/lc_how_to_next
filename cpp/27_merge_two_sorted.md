# 合并两个有序链表（LeetCode #21）

## 题目描述

> 将两个升序链表合并为一个升序链表。

**示例：** `1→2→4` 和 `1→3→4` → `1→1→2→3→4→4`

---

## 梯度分析

### 🔵 第一层：递归

```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
```

---

### 🟢 第二层：迭代尾插法 O(1) 空间

```cpp
ListNode dummy(0);
ListNode* cur = &dummy;
while (l1 && l2) {
    if (l1->val <= l2->val) { cur->next = l1; l1 = l1->next; }
    else { cur->next = l2; l2 = l2->next; }
    cur = cur->next;
}
cur->next = l1 ? l1 : l2;
return dummy.next;
```

**复杂度：**
- 时间：O(n+m)
- 空间：O(1)

---

## 破题总结

> **迭代尾插法：dummy 节点简化边界，逐个比较两链表头部将较小节点接入结果链表尾部，遍历完即得合并后的有序链表。**
