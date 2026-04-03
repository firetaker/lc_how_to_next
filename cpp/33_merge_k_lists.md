# 合并 K 个升序链表（LeetCode #23）

## 题目描述

> 合并 K 个升序链表为一个升序链表。

**示例：** `[1→4→5]`, `[1→3→4]`, `[2→6]` → `1→1→2→3→4→4→5→6`

---

## 梯度分析

### 🔵 第一层：两两合并 O(kN)

---

### 🟢 第二层：最小堆 O(N log k)

```cpp
struct Cmp { bool operator()(ListNode* a, ListNode* b) const { return a->val > b->val; } };
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
    for (auto node : lists) if (node) heap.push(node);
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (!heap.empty()) {
        ListNode* cur = heap.top(); heap.pop();
        tail->next = cur;
        tail = tail->next;
        if (cur->next) heap.push(cur->next);
    }
    return dummy.next;
}
```

**复杂度：**
- 时间：O(N log k)
- 空间：O(k)

---

## 破题总结

> **最小堆归并：K 个链表头节点入堆，每次弹出堆顶接入结果并将其下一节点入堆——始终保持堆顶为全局最小，K 路归并的经典方法。**
