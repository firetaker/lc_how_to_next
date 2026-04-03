/**
 * LeetCode #24: 两两交换链表中的节点
 * 题目: 每两个节点交换一次，返回新链表头。
 * 解法: 迭代 - 维护 prev（已处理部分尾节点），
 *       交换 curr 和 next_pair，然后重连链表。
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        while (prev->next && prev->next->next) {
            ListNode* curr = prev->next;
            ListNode* nxt_pair = prev->next->next;
            curr->next = nxt_pair->next;
            nxt_pair->next = curr;
            prev->next = nxt_pair;
            prev = curr;
        }
        return dummy.next;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1,
                    new ListNode(2,
                    new ListNode(3,
                    new ListNode(4))));
    ListNode* res = sol.swapPairs(head);
    while (res) { cout << res->val << " "; res = res->next; } // 2 1 4 3
    cout << endl;
    return 0;
}
