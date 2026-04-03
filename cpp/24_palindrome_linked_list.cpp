/**
 * LeetCode #234: 回文链表
 * 题目: 判断链表是否是回文。
 * 解法: 快慢指针找中点 + 反转后半链表 - 快指针走两步慢指针走一步找中点，
 *       反转后半部分，然后从两端向中间比较。
 * 时间 O(n)，空间 O(1)。
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 反转后半部分
        ListNode *prev = nullptr, *cur = slow->next;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        slow->next = nullptr;
        // 比较
        ListNode *p1 = head, *p2 = prev;
        while (p2) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};

int main() {
    Solution sol;
    ListNode *n1 = new ListNode(1), *n2 = new ListNode(2),
             *n3 = new ListNode(2), *n4 = new ListNode(1);
    n1->next = n2; n2->next = n3; n3->next = n4;
    cout << sol.isPalindrome(n1) << endl; // 1 (true)
    return 0;
}
