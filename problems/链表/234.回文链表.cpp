#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* listToLinkedList(vector<int> lst) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (int val : lst) {
        cur->next = new ListNode(val);
        cur = cur->next;
    }
    return dummy->next;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    // 找到链表的中点
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 反转后半部分链表
    ListNode* prev = nullptr;
    ListNode* cur = slow->next;
    while (cur) {
        ListNode* nextNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
    }
    // 比较前半部分和反转后的后半部分
    ListNode* p1 = head;
    ListNode* p2 = prev;
    while (p2) {
        if (p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

int main() {
    // 测试用例1: 1->2 不是回文链表
    ListNode* head1 = listToLinkedList({1, 2});
    cout << "测试1 - [1,2] 是回文链表:" << endl;
    cout << "  输出: " << (isPalindrome(head1) ? "True" : "False") << endl;

    // 测试用例2: 1->2->2->1 是回文链表
    ListNode* head2 = listToLinkedList({1, 2, 2, 1});
    cout << "\n测试2 - [1,2,2,1] 是回文链表:" << endl;
    cout << "  输出: " << (isPalindrome(head2) ? "True" : "False") << endl;

    // 测试用例3: 1->2->3->2->1 是回文链表
    ListNode* head3 = listToLinkedList({1, 2, 3, 2, 1});
    cout << "\n测试3 - [1,2,3,2,1] 是回文链表:" << endl;
    cout << "  输出: " << (isPalindrome(head3) ? "True" : "False") << endl;

    return 0;
}
