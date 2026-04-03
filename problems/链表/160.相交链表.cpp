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

vector<int> linkedListToList(ListNode* node) {
    vector<int> result;
    while (node) {
        result.push_back(node->val);
        node = node->next;
    }
    return result;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;
    ListNode* pa = headA;
    ListNode* pb = headB;
    while (pa != pb) {
        pa = pa ? pa->next : headB;
        pb = pb ? pb->next : headA;
    }
    return pa;
}

void printList(ListNode* node) {
    cout << "[";
    while (node) {
        cout << node->val;
        if (node->next) cout << ",";
        node = node->next;
    }
    cout << "]";
}

int main() {
    // 测试用例1: 相交于节点 8
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;
    ListNode* result = getIntersectionNode(headA, headB);
    cout << "测试1 - 相交链表:" << endl;
    cout << "  输出: " << (result ? to_string(result->val) : "null") << endl;

    // 测试用例2: 不相交
    ListNode* headC = listToLinkedList({1, 2, 3});
    ListNode* headD = listToLinkedList({4, 5, 6});
    ListNode* result2 = getIntersectionNode(headC, headD);
    cout << "\n测试2 - 不相交链表:" << endl;
    cout << "  输出: " << (result2 ? to_string(result2->val) : "null") << endl;

    // 测试用例3: 完全重合
    ListNode* headE = listToLinkedList({1, 2, 3});
    ListNode* result3 = getIntersectionNode(headE, headE);
    cout << "\n测试3 - 完全重合链表:" << endl;
    cout << "  输出: " << (result3 ? to_string(result3->val) : "null") << endl;

    return 0;
}
