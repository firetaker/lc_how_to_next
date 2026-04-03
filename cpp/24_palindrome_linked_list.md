# 回文链表（LeetCode #234）

## 题目描述

> 判断链表是否是回文。

**示例：** `1→2→2→1` → `True`

---

## 梯度分析

### 🔵 第一层：存入数组双指针比较

O(n) 时间，O(n) 空间。

---

### 🟢 第二层：快慢指针找中点 + 反转后半 O(n) / O(1)

```cpp
// 找中点
ListNode *slow = head, *fast = head;
while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
}
// 反转后半部分
ListNode *prev = nullptr, *cur = slow->next;
while (cur) {
    ListNode* nxt = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nxt;
}
slow->next = nullptr;
// 比较前半和反转后半
ListNode *p1 = head, *p2 = prev;
while (p2) {
    if (p1->val != p2->val) return false;
    p1 = p1->next;
    p2 = p2->next;
}
return true;
```

**图解 `1→2→2→1`：**

```
找中点: slow 停在第2个2
反转后半: 2→1 → 1→2
比较: p1=1 vs p2=1 ✅, p1=2 vs p2=2 ✅ → 回文 ✅
```

**复杂度：**
- 时间：O(n)
- 空间：O(1)

---

## 破题总结

> **快慢指针找中点，反转后半链表，然后从两端向中间比较——若完全匹配则为回文链表，O(n) 时间 O(1) 空间。**
