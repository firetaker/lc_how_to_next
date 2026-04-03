/**
 * LeetCode #146: LRU 缓存
 * 题目: 实现最近最少使用缓存，支持 get 和 put，均 O(1)。
 * 解法: 哈希表 + 双向链表 - 哈希表提供 O(1) 键查找，
 *       双向链表维护访问顺序（头部最新，尾部最旧）。
 *       get：将节点移到头部；put：新节点插头部，满时删尾部。
 * 时间 O(1)，空间 O(capacity)。
 */

#include <iostream>
#include <unordered_map>
using namespace std;

struct DLinkedNode {
    int key, val;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > cap) {
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        } else {
            DLinkedNode* node = cache[key];
            node->val = value;
            moveToHead(node);
        }
    }

private:
    int cap, size;
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode *head, *tail;

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

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // 1
    cache.put(3, 3);
    cout << cache.get(2) << endl; // -1 (已淘汰)
    cache.put(4, 4);
    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4
    return 0;
}
