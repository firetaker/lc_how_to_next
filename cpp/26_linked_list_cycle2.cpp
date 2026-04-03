/**
 * LeetCode #142: 环形链表 II
 * 题目: 返回链表入环的第一个节点，若无环返回 nullptr。
 * 解法: Floyd 判圈（快慢指针）两步:
 *       1. 快慢指针相遇，证明有环
 *       2. 慢指针在相遇点，头指针从 head 同速前进，再次相遇点即为入环点
 * 数学：设非环部分长度 a，入环点到相遇点 b，环长 c。
 * 2(a+b) = a + b + nc → a = (n-1)c + (c-b)，故相遇点即为入环点。
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
    ListNode* detectCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* slow2 = head;
                while (slow != slow2) {
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

int main() {
    Solution sol;
    ListNode *n3 = new ListNode(3), *n2 = new ListNode(2),
             *n0 = new ListNode(0), *nm4 = new ListNode(-4);
    n3->next = n2; n2->next = n0; n0->next = nm4; nm4->next = n2;
    ListNode* res = sol.detectCycle(n3);
    cout << (res ? res->val : -1) << endl; // 2
    return 0;
}
