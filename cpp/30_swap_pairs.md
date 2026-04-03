# 两两交换链表中的节点（LeetCode #24）

## 题目描述

> 每两个节点交换一次，返回新链表头。

**示例：** `1→2→3→4` → `2→1→4→3`

---

## 梯度分析

### 🔵 第一层：递归

```cpp
ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* nxt = head->next;
    head->next = swapPairs(nxt->next);
    nxt->next = head;
    return nxt;
}
```

---

### 🟢 第二层：迭代三指针 O(1) 空间

```cpp
ListNode dummy(0, head);
ListNode* prev = &dummy;
while (prev->next && prev->next->next) {
    ListNode* curr = prev->next;
    ListNode* nxt_pair = prev->next->next;
    curr->next = nxt_pair->next;
    nxt_pair->next = curr;
    prev->next = nxt_pair;
    prev = curr;
}
return dummy.next;
```

**复杂度：**
- 时间：O(n)
- 空间：O(1)

---

## 破题总结

> **迭代三指针：prev 指向已处理完的尾节点，每次取相邻两个节点 curr 和 nxt_pair 进行交换，重连后 prev 移到交换后的尾节点，继续处理下一对。**
