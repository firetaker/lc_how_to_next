#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

pair<ListNode*, ListNode*> listToLinkedListWithCycle(vector<int> lst, int cyclePos) {
    if (lst.empty()) return {nullptr, nullptr};
    vector<ListNode*> nodes;
    for (int val : lst) {
        nodes.push_back(new ListNode(val));
    }
    for (int i = 0; i < (int)nodes.size() - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    ListNode* cycleNode = nullptr;
    if (cyclePos != -1 && cyclePos < (int)nodes.size()) {
        nodes.back()->next = nodes[cyclePos];
        cycleNode = nodes[cyclePos];
    }
    return {nodes[0], cycleNode};
}

ListNode* detectCycle(ListNode* head) {
    if (!head || !head->next) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            ListNode* slow2 = head;
            while (slow != slow2) {
                slow = slow->next;
                slow2 = slow2->next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main() {
    // 测试用例1: 3->2->0->-4, 尾部连接到索引1 (值为2)
    pair<ListNode*, ListNode*> p1 = listToLinkedListWithCycle({3, 2, 0, -4}, 1);
    ListNode* head1 = p1.first;
    ListNode* expected1 = p1.second;
    ListNode* result1 = detectCycle(head1);
    cout << "测试1 - 链表 [3,2,0,-4] 入环点在索引1:" << endl;
    cout << "  预期入环节点值: " << (expected1 ? to_string(expected1->val) : "null") << endl;
    cout << "  输出: " << (result1 ? to_string(result1->val) : "null") << endl;

    // 测试用例2: 1->2, 尾部连接到头节点 (索引0)
    pair<ListNode*, ListNode*> p2 = listToLinkedListWithCycle({1, 2}, 0);
    ListNode* head2 = p2.first;
    ListNode* expected2 = p2.second;
    ListNode* result2 = detectCycle(head2);
    cout << "\n测试2 - 链表 [1,2] 入环点在头节点:" << endl;
    cout << "  预期入环节点值: " << (expected2 ? to_string(expected2->val) : "null") << endl;
    cout << "  输出: " << (result2 ? to_string(result2->val) : "null") << endl;

    // 测试用例3: 1 无环
    pair<ListNode*, ListNode*> p3 = listToLinkedListWithCycle({1}, -1);
    ListNode* head3 = p3.first;
    ListNode* result3 = detectCycle(head3);
    cout << "\n测试3 - 链表 [1] 无环:" << endl;
    cout << "  输出: " << (result3 ? to_string(result3->val) : "null") << endl;

    return 0;
}
