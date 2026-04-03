/**
 * LeetCode #206: 反转链表
 * 题目: 反转单链表，返回新链表头。
 * 解法: 头插法 / 双指针迭代 - 遍历原链表，将每个节点以头插法插入新链表。
 *       prev=None 为新链表头，cur 从 head 遍历，每次头插。
 * 时间 O(n)，空间 O(1)。
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};

int main() {
    Solution sol;
    ListNode *n1 = new ListNode(1), *n2 = new ListNode(2),
             *n3 = new ListNode(3), *n4 = new ListNode(4), *n5 = new ListNode(5);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5;
    ListNode* rev = sol.reverseList(n1);
    while (rev) { cout << rev->val << " "; rev = rev->next; } // 5 4 3 2 1
    cout << endl;
    return 0;
}
