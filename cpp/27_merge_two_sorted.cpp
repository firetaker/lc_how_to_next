/**
 * LeetCode #21: 合并两个有序链表
 * 题目: 将两个升序链表合并为一个升序链表。
 * 解法: 迭代尾插法 - 维护 dummy 头节点，比较两链表头部，较小的尾插。
 * 时间 O(n+m)，空间 O(1)。
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x=0, ListNode* n=nullptr) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) { cur->next = l1; l1 = l1->next; }
            else { cur->next = l2; l2 = l2->next; }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

int main() {
    Solution sol;
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* res = sol.mergeTwoLists(l1, l2);
    while (res) { cout << res->val << " "; res = res->next; } // 1 1 2 3 4 4
    cout << endl;
    return 0;
}
