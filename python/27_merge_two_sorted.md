# 合并两个有序链表（LeetCode #21）

## 题目描述

> 将两个升序链表合并为一个升序链表。

**示例：**
- `1→2→4` 和 `1→3→4` → `1→1→2→3→4→4`

---

## 梯度分析

### 🔵 第一层：递归

```python
if not l1: return l2
if not l2: return l1
if l1.val <= l2.val:
    l1.next = mergeTwoLists(l1.next, l2)
    return l1
else:
    l2.next = mergeTwoLists(l1, l2.next)
    return l2
```

### 🟢 第二层：迭代尾插法 O(1) 空间

**核心洞察：** 维护一个 dummy 头节点，遍历两链表，每次将较小节点尾插到结果链表。

```python
dummy = ListNode(0)
cur = dummy
while l1 and l2:
    if l1.val <= l2.val:
        cur.next = l1
        l1 = l1.next
    else:
        cur.next = l2
        l2 = l2.next
    cur = cur.next
cur.next = l1 or l2
return dummy.next
```

**图解 `1→2→4` 和 `1→3→4`：**

```
dummy→?
比较 1 vs 1 → 取1 → dummy→1, cur=1, l1→2→4
比较 2 vs 1 → 取1 → dummy→1→1, cur=1, l2→3→4
比较 2 vs 3 → 取2 → dummy→1→1→2, cur=2, l1→4→4
比较 4 vs 3 → 取3 → dummy→1→1→2→3, cur=3, l2→4→4
比较 4 vs 4 → 取4 → dummy→1→1→2→3→4, cur=4, l1=None
cur.next = l2 = 4 → dummy→1→1→2→3→4→4 ✅
```

**复杂度：**
- 时间：O(n+m)
- 空间：O(1)

---

## 破题总结

> **迭代尾插法：dummy 节点简化边界处理，逐个比较两链表头部，将较小节点接入结果链表尾部，遍历完即得合并后的有序链表。**
