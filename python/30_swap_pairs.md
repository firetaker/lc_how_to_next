# 两两交换链表中的节点（LeetCode #24）

## 题目描述

> 每两个节点交换一次，返回新链表头。

**示例：**
- `1→2→3→4` → `2→1→4→3`

---

## 梯度分析

### 🔵 第一层：递归

```python
if not head or not head.next: return head
nxt = head.next
head.next = swapPairs(nxt.next)
nxt.next = head
return nxt
```

### 🟢 第二层：迭代三指针 O(1) 空间

**核心洞察：** 维护 prev（已处理部分尾节点），交换 curr 和 nxt_pair 两个节点。

```python
dummy = ListNode(0, head)
prev = dummy
while prev.next and prev.next.next:
    curr = prev.next
    nxt_pair = prev.next.next
    # 交换 curr 和 nxt_pair
    curr.next = nxt_pair.next
    nxt_pair.next = curr
    prev.next = nxt_pair
    # prev 移到交换后的尾（curr）
    prev = curr
return dummy.next
```

**图解 `1→2→3→4→5`：**

```
初始: dummy→1→2→3→4, prev=dummy

第1轮交换 (1,2):
  curr=1, nxt_pair=2
  交换: 1.next=3, 2.next=1, dummy.next=2
  结果: dummy→2→1→3→4
  prev=1

第2轮交换 (3,4):
  prev.next=3, prev.next.next=4 存在
  curr=3, nxt_pair=4
  交换: 3.next=5, 4.next=3, 1.next=4
  结果: dummy→2→1→4→3→5
  prev=3

第3轮: prev.next=5 存在，但 prev.next.next=None
  5 alone 不够一对，退出

结果: 2→1→4→3→5 ✅
```

**复杂度：**
- 时间：O(n)
- 空间：O(1)

---

## 破题总结

> **迭代三指针：prev 指向已处理完的尾节点，每次取相邻两个节点 curr 和 nxt_pair 进行交换，重连链表后 prev 移到交换后的尾节点，继续处理下一对。**
