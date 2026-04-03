# 排序链表（LeetCode #148）

## 题目描述

> 将链表升序排列。要求 O(n log n) 时间，O(1) 空间。

---

## 梯度分析

### 🔵 第一层：转换为数组后排序

存入数组，用 Timsort/内置排序，再重建链表。O(n log n) 时间，但 O(n) 空间。

---

### 🟢 第二层：归并排序（分治）O(n log n) / O(1)

**核心洞察：** 链表的归并排序天然满足 O(1) 额外空间要求——找中点快慢指针无需额外空间，合并只需调整指针。

**分治三步：**
1. **找中点**：快慢指针，slow 最终停在中点或中点偏后
2. **递归排序**：左右两半分别排序
3. **合并有序链表**：两个有序链表合并

```python
def sortList(head):
    if not head or not head.next:
        return head
    # 找中点断开
    slow = fast = head
    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next
    mid = slow.next
    slow.next = None  # 断开
    # 递归排序
    left = sortList(head)
    right = sortList(mid)
    # 合并
    return merge(left, right)

def merge(l1, l2):
    dummy = ListNode(0)
    cur = dummy
    while l1 and l2:
        if l1.val <= l2.val:
            cur.next = l1; l1 = l1.next
        else:
            cur.next = l2; l2 = l2.next
        cur = cur.next
    cur.next = l1 or l2
    return dummy.next
```

**复杂度分析：**
- 每层合并 O(n)，共 log n 层 → 总 O(n log n)
- 递归栈深度 O(log n)
- 找中点 O(n)，合并 O(n)

**图解 `4→2→1→3`：**

```
递归分解:
  4→2→1→3
  找中点: 4→2 (slow 在 2)
  断开: left=4→2, right=1→3

  left=4→2:
    找中点: 4 (slow 在 4)
    断开: left=4, right=2
    merge(4, 2) → 2→4

  right=1→3:
    找中点: 1 (slow 在 1)
    断开: left=1, right=3
    merge(1, 3) → 1→3

  merge(2→4, 1→3):
    2≤3 → 2→4, cur=2
    4>1 → 2→1→3, cur=1
    4>3 → 2→1→3→4
    结果: 1→2→3→4 ✅
```

---

## 破题总结

> **归并排序（分治）：快慢指针找中点递归分治，合并两个有序链表——链表天然适合归并（无需额外数组），O(n log n) 时间，O(log n) 递归栈空间。**
