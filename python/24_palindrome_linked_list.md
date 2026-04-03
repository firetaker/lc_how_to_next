# 回文链表（LeetCode #234）

## 题目描述

> 判断链表是否是回文。

**示例：**
- `1→2→2→1` → `True`
- `1→2` → `False`

---

## 梯度分析

### 🔵 第一层：存入数组双指针比较

将链表全部存入数组，再用双指针从两端向中间比较。O(n) 时间，O(n) 空间。

---

### 🟢 第二层：快慢指针找中点 + 反转后半部分 O(1) 空间

**核心洞察：**
1. 快指针走两步，慢指针走一步，找到链表中点（奇数归为后半部分）
2. 反转后半部分链表
3. 从两端向中间比较
4. 可选：恢复链表原状

```python
# 找中点
slow = fast = head
while fast.next and fast.next.next:
    slow = slow.next
    fast = fast.next.next
mid = slow  # 中点或中点偏后

# 反转后半部分
prev = None
cur = mid.next
while cur:
    nxt = cur.next
    cur.next = prev
    prev = cur
    cur = nxt
mid.next = None  # 断开前后

# 比较前半和反转后半
p1, p2 = head, prev
while p2:  # p2 为后半，长度 <= 前半
    if p1.val != p2.val: return False
    p1 = p1.next
    p2 = p2.next
return True
```

**图解 `1→2→2→1`：**

```
找中点: slow 停在第2个2
  1→2→2→1
      ↑slow  fast

反转后半:
  原后半: 2→1
  反转后: 1→2

比较:
  p1: 1, p2: 1 → ✅
  p1: 2, p2: 2 → ✅
  p2=None → 结束，回文 ✅
```

**复杂度：**
- 时间：O(n)
- 空间：O(1)

---

## 破题总结

> **快慢指针找中点，反转后半链表，然后从两端向中间比较——若完全匹配则为回文链表，O(n) 时间 O(1) 空间。**
