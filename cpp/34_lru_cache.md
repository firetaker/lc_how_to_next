# LRU 缓存（LeetCode #146）

## 题目描述

> 实现最近最少使用（LRU）缓存，支持 get 和 put，均 O(1)。

---

## 梯度分析

### 🔵 第一层：哈希表 + 列表

get O(1)，put O(1)，但删除最旧元素 O(n)。

---

### 🟢 第二层：哈希表 + 双向链表 O(1) / O(capacity)

```cpp
struct DLinkedNode {
    int key, val;
    DLinkedNode *prev, *next;
    DLinkedNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int cap, size;
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode *head, *tail;
public:
    LRUCache(int capacity) : cap(capacity), size(0) {
        head = new DLinkedNode(); tail = new DLinkedNode();
        head->next = tail; tail->prev = head;
    }
    int get(int key) {
        if (!cache.count(key)) return -1;
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->val;
    }
    void put(int key, int value) {
        if (cache.count(key)) {
            DLinkedNode* node = cache[key];
            node->val = value;
            moveToHead(node);
        } else {
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > cap) {
                DLinkedNode* lru = removeTail();
                cache.erase(lru->key);
                delete lru;
                --size;
            }
        }
    }
private:
    void addToHead(DLinkedNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void moveToHead(DLinkedNode* node) { removeNode(node); addToHead(node); }
    DLinkedNode* removeTail() { DLinkedNode* lru = tail->prev; removeNode(lru); return lru; }
};
```

**复杂度：**
- 时间：O(1)
- 空间：O(capacity)

---

## 破题总结

> **哈希表提供 O(1) 查找，双向链表维护访问顺序（头最新尾最旧）。get 将节点移到头部，put 插入头部后删除尾部（满时）。两个数据结构各司其职，保证 O(1)。**
