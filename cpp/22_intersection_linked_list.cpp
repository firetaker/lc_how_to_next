/**
 * LeetCode #160: 相交链表
 * 题目: 判断两个链表是否相交，返回相交的第一个节点。
 * 解法: 双指针切换法 - 指针 a 走完链表 A 后切换到链表 B，
 *       指针 b 走完链表 B 后切换到链表 A。
 *       数学原理：a走过的总路程 = b走过的总路程 = (A长度+B长度)，
 *       消除尾部差距后必在相交点相遇。O(n+m)，O(1)。
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};

int main() {
    // 1->2->3->4
    ListNode *n1 = new ListNode(1), *n2 = new ListNode(2),
             *n3 = new ListNode(3), *n4 = new ListNode(4);
    n1->next = n2; n2->next = n3; n3->next = n4;
    // B: 5->3->4
    ListNode *b1 = new ListNode(5);
    b1->next = n3;
    Solution sol;
    ListNode* res = sol.getIntersectionNode(n1, b1);
    cout << (res ? res->val : -1) << endl; // 3
    return 0;
}
