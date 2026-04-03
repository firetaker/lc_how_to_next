/**
 * LeetCode #19: 删除链表的倒数第 N 个节点
 * 题目: 删除倒数第 n 个节点，返回头节点。
 * 解法: 前后指针（距离差）- 快指针先走 n+1 步，然后快慢同速前进。
 *       当快指针到达末尾时，慢指针的下一个就是待删除节点。
 * 时间 O(n)，空间 O(1)。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode *fast = &dummy, *slow = &dummy;
        for (int i = 0; i < n + 1; ++i) fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1,
                    new ListNode(2,
                    new ListNode(3,
                    new ListNode(4,
                    new ListNode(5)))));
    ListNode* res = sol.removeNthFromEnd(head, 2);
    while (res) { cout << res->val << " "; res = res->next; } // 1 2 3 5
    cout << endl;
    return 0;
}
