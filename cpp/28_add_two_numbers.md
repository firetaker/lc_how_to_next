# 两数相加（LeetCode #2）

## 题目描述

> 两链表表示非负整数（逆序存储），返回相加结果链表。

**示例：** `2→4→3` + `5→4→6` = `7→0→8`（342 + 465 = 807）

---

## 梯度分析

### 🔵 第一层：存入整数计算

Python 可直接大整数运算，但链表意义不大。

---

### 🟢 第二层：逐位迭代处理进位 O(max(n,m))

```cpp
ListNode dummy(0);
ListNode* cur = &dummy;
int carry = 0;
while (l1 || l2 || carry) {
    int total = carry;
    if (l1) { total += l1->val; l1 = l1->next; }
    if (l2) { total += l2->val; l2 = l2->next; }
    cur->next = new ListNode(total % 10);
    cur = cur->next;
    carry = total / 10;
}
return dummy.next;
```

**图解 `99 + 1 = 100`：**

```
位1: 9+1=10 → 节点0, carry=1
位2: 9+0+1=10 → 节点0, carry=1
位3: carry=1 → 节点1, carry=0
结果: 0→0→1 (100) ✅
```

**复杂度：**
- 时间：O(max(n,m))
- 空间：O(max(n,m))

---

## 破题总结

> **逐位相加维护进位：每位结果 = (v1+v2+carry)%10，进位 = (v1+v2+carry)/10，遍历完两链表及进位即得结果链表。**
