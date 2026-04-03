/**
 * LeetCode #138: 随机链表的复制
 * 题目: 复制带 random 指针的链表。
 * 解法: 节点后插入复制节点 + 分离（三步）:
 *       1. 原链表每节点后插入复制节点（random 暂未设置）
 *       2. 遍历设置复制节点的 random（copy.random = origin.random.next）
 *       3. 分离两个链表
 * 时间 O(n)，空间 O(1)（不计结果空间）。
 */

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
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
    }
};

int main() {
    Solution sol;
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5;
    n2->random = n1; n3->random = n5; n4->random = n3; n5->random = n1;
    Node* copied = sol.copyRandomList(n1);
    cout << copied->val << " " << copied->next->val << endl; // 7 13
    return 0;
}
