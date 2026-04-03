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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    for (int i = 0; i < n + 1; i++) {
        fast = fast->next;
    }
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
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
    // 测试用例1: [1,2,3,4,5] 删除倒数第2个节点 (值为4) -> [1,2,3,5]
    ListNode* head1 = listToLinkedList({1, 2, 3, 4, 5});
    ListNode* result1 = removeNthFromEnd(head1, 2);
    cout << "测试1 - [1,2,3,4,5] 删除倒数第2个节点:" << endl;
    cout << "  输出: ";
    printList(result1);
    cout << endl;

    // 测试用例2: [1] 删除倒数第1个节点 -> []
    ListNode* head2 = listToLinkedList({1});
    ListNode* result2 = removeNthFromEnd(head2, 1);
    cout << "\n测试2 - [1] 删除倒数第1个节点:" << endl;
    cout << "  输出: ";
    printList(result2);
    cout << endl;

    // 测试用例3: [1,2] 删除倒数第1个节点 (值为2) -> [1]
    ListNode* head3 = listToLinkedList({1, 2});
    ListNode* result3 = removeNthFromEnd(head3, 1);
    cout << "\n测试3 - [1,2] 删除倒数第1个节点:" << endl;
    cout << "  输出: ";
    printList(result3);
    cout << endl;

    return 0;
}
