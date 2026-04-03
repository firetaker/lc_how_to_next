/**
 * LeetCode #2: 两数相加
 * 题目: 两链表表示非负整数，每位逆序存储，返回相加结果链表。
 * 解法: 迭代 - 从链表头部逐位相加，维护进位 carry = (v1+v2+carry)/10，
 *       新节点值 = (v1+v2+carry)%10。O(max(n,m))，O(max(n,m))。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int total = carry;
            if (l1) { total += l1->val; l1 = l1->next; }
            if (l2) { total += l2->val; l2 = l2->next; }
            cur->next = new ListNode(total % 10);
            cur = cur->next;
            carry = total / 10;
        }
        return dummy.next;
    }
};

int main() {
    Solution sol;
    // 342 + 465 = 807 → 7->0->8
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(4, new ListNode(6)));
    ListNode* res = sol.addTwoNumbers(l1, l2);
    while (res) { cout << res->val << " "; res = res->next; } // 7 0 8
    cout << endl;
    return 0;
}
