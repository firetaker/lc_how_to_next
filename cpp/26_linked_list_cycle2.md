# 环形链表 II（LeetCode #142）

## 题目描述

> 返回链表入环的第一个节点，若无环返回 nullptr。

---

## 梯度分析

### 🔵 第一层：哈希集合

O(n) 时间，O(n) 空间。

---

### 🟢 第二层：Floyd 判圈两步法 O(n) / O(1)

```cpp
ListNode *slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) break;
}
if (!fast || !fast->next) return nullptr;
ListNode *slow2 = head;
while (slow != slow2) {
    slow = slow->next;
    slow2 = slow2->next;
}
return slow;
```

**数学：设非环部分长 a，入环点到相遇点长 b，环长 c。2(a+b)=a+b+nc → a=(n-1)c+(c-b)，故从 head 和相遇点同速前进会在入环点相遇。**

**复杂度：**
- 时间：O(n)
- 空间：O(1)

---

## 破题总结

> **Floyd 判圈两步法：快慢指针相遇证明有环，头指针和慢指针同速前进再次相遇即为入环点——数学推导 a=(m-1)c+(c-b) 保证相遇位置正确。**
