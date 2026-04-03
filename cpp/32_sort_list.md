# 排序链表（LeetCode #148）

## 题目描述

> 将链表升序排列。要求 O(n log n) 时间，O(1) 空间。

---

## 梯度分析

### 🔵 第一层：存入数组排序后重建

O(n log n) 时间，O(n) 空间。

---

### 🟢 第二层：归并排序（分治）O(n log n) / O(1)

```cpp
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    // 找中点
    ListNode *slow = head, *fast = head->next;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    // 递归排序
    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);
    return merge(left, right);
}

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) { cur->next = l1; l1 = l1->next; }
        else { cur->next = l2; l2 = l2->next; }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return dummy.next;
}
```

**复杂度：**
- 时间：O(n log n)
- 空间：O(log n)（递归栈）

---

## 破题总结

> **归并排序（分治）：快慢指针找中点递归分治，合并两个有序链表——链表天然适合归并（无需额外数组），O(n log n) 时间。**
