# 随机链表的复制（LeetCode #138）

## 题目描述

> 复制带 random 指针的链表。

---

## 梯度分析

### 🔵 第一层：哈希表记录原节点→复制节点

O(n) 时间，O(n) 空间。

---

### 🟢 第二层：三步原地复制 O(n) / O(1)

```cpp
// Step 1: 插入复制节点
for (Node* cur = head; cur; ) {
    Node* copy = new Node(cur->val);
    copy->next = cur->next;
    cur->next = copy;
    cur = copy->next;
}
// Step 2: 设置 random
for (Node* cur = head; cur; cur = cur->next->next)
    if (cur->random)
        cur->next->random = cur->random->next;
// Step 3: 分离
Node dummy(0);
Node* tail = &dummy;
for (Node* cur = head; cur; cur = cur->next) {
    tail->next = cur->next;
    tail = tail->next;
    cur->next = cur->next->next;
}
return dummy.next;
```

**图解：**

```
Step1 插入后: 1→1'→2→2'→3→3'→...
Step2 设置 random: copy.random = origin.random.next（复制版的对应节点）
Step3 分离: 交替提取复制节点，还原原链表
```

**复杂度：**
- 时间：O(n)
- 空间：O(1)（不计结果空间）

---

## 破题总结

> **三步原地复制：插入复制节点（copy.next=origin.next）→ 设置复制节点的 random（copy.random=origin.random.next）→ 交替分离两个链表。插入天然保证了复制节点与原节点的对应关系。**
