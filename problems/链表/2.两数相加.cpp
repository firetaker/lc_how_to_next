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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        int total = val1 + val2 + carry;
        carry = total / 10;
        cur->next = new ListNode(total % 10);
        cur = cur->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    return dummy->next;
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
    // 测试用例1: 342 + 465 = 807
    ListNode* l1 = listToLinkedList({2, 4, 3});
    ListNode* l2 = listToLinkedList({5, 6, 4});
    ListNode* result = addTwoNumbers(l1, l2);
    cout << "测试1 - 342 + 465:" << endl;
    cout << "  输入: l1 = [2,4,3], l2 = [5,6,4]" << endl;
    cout << "  输出: ";
    printList(result);
    cout << endl;

    // 测试用例2: 9999999 + 9999 = 10009998
    l1 = listToLinkedList({9, 9, 9, 9, 9, 9, 9});
    l2 = listToLinkedList({9, 9, 9, 9});
    result = addTwoNumbers(l1, l2);
    cout << "\n测试2 - 9999999 + 9999:" << endl;
    cout << "  输入: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]" << endl;
    cout << "  输出: ";
    printList(result);
    cout << endl;

    // 测试用例3: 0 + 0 = 0
    l1 = listToLinkedList({0});
    l2 = listToLinkedList({0});
    result = addTwoNumbers(l1, l2);
    cout << "\n测试3 - 0 + 0:" << endl;
    cout << "  输入: l1 = [0], l2 = [0]" << endl;
    cout << "  输出: ";
    printList(result);
    cout << endl;

    return 0;
}
