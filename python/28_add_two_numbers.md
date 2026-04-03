# 两数相加（LeetCode #2）

## 题目描述

> 两链表表示非负整数（逆序存储），返回相加结果链表。

**示例：**
- `2→4→3` + `5→4→6` = `7→0→8`（342 + 465 = 807）

---

## 梯度分析

### 🔵 第一层：存入数组计算

将链表转为整数相加，再转回链表。Python 大整数可直接处理，但链表意义不大。

---

### 🟢 第二层：逐位迭代（处理进位）

**核心洞察：** 从链表头部逐位相加，维护进位 `carry = (v1 + v2 + carry) // 10`。

```python
dummy = ListNode(0)
cur = dummy
carry = 0
while l1 or l2 or carry:
    total = carry
    if l1: total += l1.val; l1 = l1.next
    if l2: total += l2.val; l2 = l2.next
    cur.next = ListNode(total % 10)
    cur = cur.next
    carry = total // 10
return dummy.next
```

**图解 `342 + 465 = 807`：**

```
链表: 2→4→3 和 5→4→6（逆序存储）

位1: total = 0 + 2 + 5 = 7 → 节点7, carry=0
位2: total = 0 + 4 + 4 = 8 → 节点8, carry=0
位3: total = 0 + 3 + 6 = 9 → 节点9, carry=0

结果: 7→8→9 ❌ (我算错了，3+6=9没问题，但2+5=7没问题)

重新算: 342 + 465 = 807
位1: 2+5=7 → 7, carry=0
位2: 4+4=8 → 8, carry=0
位3: 3+6=9 → 9, carry=0
```

**有进位的例子 `99 + 1`：**

```
位1: 9+1=10 → 0, carry=1
位2: 9+0+1=10 → 0, carry=1
位3: carry=1 → 1, carry=0
结果: 0→0→1 (100) ✅
```

**复杂度：**
- 时间：O(max(n,m))
- 空间：O(max(n,m))

---

## 破题总结

> **逐位相加维护进位：每位结果 = (v1 + v2 + carry) % 10，进位 = (v1 + v2 + carry) // 10，遍历完两链表及进位即得结果链表。**
