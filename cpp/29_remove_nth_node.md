# 删除链表的倒数第 N 个节点（LeetCode #19）

## 题目描述

> 删除链表的倒数第 n 个节点，返回头节点。

**示例：** `1→2→3→4→5`, n=2 → `1→2→3→5`

---

## 梯度分析

### 🔵 第一层：先遍历得到长度，再删除

两次遍历。O(n) 时间。

---

### 🟢 第二层：前后指针（距离差）O(n) / O(1)

```cpp
ListNode dummy(0, head);
ListNode *fast = &dummy, *slow = &dummy;
for (int i = 0; i < n + 1; ++i) fast = fast->next;
while (fast) {
    fast = fast->next;
    slow = slow->next;
}
slow->next = slow->next->next;
return dummy.next;
```

**图解 `1→2→3→4→5`, n=2：**

```
dummy→1→2→3→4→5
       ↑slow  ↑fast（先走3步到末尾）

fast 再走2步到 None:
  slow 跟着走2步 → slow 指向节点3

slow.next = slow.next.next → 删除节点4
结果: 1→2→3→5 ✅
```

**复杂度：**
- 时间：O(n)
- 空间：O(1)

---

## 破题总结

> **前后指针距离差：快指针先走 n+1 步，然后同速前进直到末尾——慢指针恰好停在待删除节点的前一个位置，执行删除。**
