# 删除链表的倒数第 N 个节点（LeetCode #19）

## 题目描述

> 删除链表的倒数第 n 个节点，返回头节点。

**示例：**
- `1→2→3→4→5`, n=2 → `1→2→3→5`

---

## 梯度分析

### 🔵 第一层：先遍历得到长度，再遍历删除

先遍历一遍得到长度 L，倒数第 n 个即正数第 L-n+1 个。两次遍历。O(n) 时间。

---

### 🟢 第二层：前后指针（距离差）O(n) / O(1)

**核心洞察：** 让快指针先走 n+1 步，然后快慢同速前进。当快指针到达末尾时，慢指针的下一个就是待删除节点。

```python
dummy = ListNode(0, head)
fast = slow = dummy
for _ in range(n + 1):   # 快指针先走 n+1 步
    fast = fast.next
while fast:
    fast = fast.next
    slow = slow.next
slow.next = slow.next.next  # 删除
return dummy.next
```

**图解 `1→2→3→4→5`, n=2：**

```
dummy→1→2→3→4→5
       ↑slow  ↑fast（先走3步）

fast 再走2步到 None:
  slow 跟着走2步 → slow 指向节点 3

slow.next = slow.next.next:
  slow.next = 4 → 改为 5
  即删除节点 4

结果: 1→2→3→5 ✅
```

**为什么是 n+1 步？**
- 快指针走到 None 时，慢指针指向待删除节点的前一个节点
- 从 dummy（头前）出发，走 n+1 步后 fast 在末尾，慢指针指向第 L-n 个节点（待删除节点的前一个）

**复杂度：**
- 时间：O(n)
- 空间：O(1)

---

## 破题总结

> **前后指针距离差：快指针先走 n+1 步，然后同速前进直到末尾——慢指针恰好停在待删除节点的前一个位置，执行删除。**
