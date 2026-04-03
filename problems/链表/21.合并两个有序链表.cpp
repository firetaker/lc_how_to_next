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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
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
    // 测试用例1: 1->2->4 和 1->3->4 合并为 1->1->2->3->4->4
    ListNode* l1 = listToLinkedList({1, 2, 4});
    ListNode* l2 = listToLinkedList({1, 3, 4});
    ListNode* result = mergeTwoLists(l1, l2);
    cout << "测试1 - 合并 [1,2,4] 和 [1,3,4]:" << endl;
    cout << "  输出: ";
    printList(result);
    cout << endl;

    // 测试用例2: 空链表和 0->1->2->3 合并为 0->1->2->3
    l1 = nullptr;
    l2 = listToLinkedList({0, 1, 2, 3});
    result = mergeTwoLists(l1, l2);
    cout << "\n测试2 - 合并 [] 和 [0,1,2,3]:" << endl;
    cout << "  输出: ";
    printList(result);
    cout << endl;

    // 测试用例3: [] 和 [] 合并为 []
    l1 = nullptr;
    l2 = nullptr;
    result = mergeTwoLists(l1, l2);
    cout << "\n测试3 - 合并 [] 和 []:" << endl;
    cout << "  输出: ";
    printList(result);
    cout << endl;

    return 0;
}
