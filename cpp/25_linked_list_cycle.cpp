/**
 * LeetCode #141: 环形链表
 * 题目: 判断链表中是否存在环。
 * 解法: 快慢指针（Floyd 判圈）- 快指针每次走两步，慢指针每次走一步。
 *       若存在环，两者必然在环内相遇。O(n)，O(1)。
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
    bool hasCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    ListNode *n1 = new ListNode(1), *n2 = new ListNode(2),
             *n3 = new ListNode(3), *n4 = new ListNode(4);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n2; // 环形
    cout << sol.hasCycle(n1) << endl; // 1 (true)
    n4->next = nullptr;
    cout << sol.hasCycle(n1) << endl; // 0 (false)
    return 0;
}
