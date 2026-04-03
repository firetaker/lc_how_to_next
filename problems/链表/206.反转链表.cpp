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

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur) {
        ListNode* nextNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
    }
    return prev;
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
    // 测试用例1: 1->2->3->4->5 反转为 5->4->3->2->1
    ListNode* head1 = listToLinkedList({1, 2, 3, 4, 5});
    ListNode* result1 = reverseList(head1);
    cout << "测试1 - 反转 [1,2,3,4,5]:" << endl;
    cout << "  输出: ";
    printList(result1);
    cout << endl;

    // 测试用例2: 1->2 反转为 2->1
    ListNode* head2 = listToLinkedList({1, 2});
    ListNode* result2 = reverseList(head2);
    cout << "\n测试2 - 反转 [1,2]:" << endl;
    cout << "  输出: ";
    printList(result2);
    cout << endl;

    // 测试用例3: 单节点
    ListNode* head3 = listToLinkedList({1});
    ListNode* result3 = reverseList(head3);
    cout << "\n测试3 - 反转 [1]:" << endl;
    cout << "  输出: ";
    printList(result3);
    cout << endl;

    return 0;
}
