#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* listToLinkedListWithCycle(vector<int> lst, int cyclePos) {
    if (lst.empty()) return nullptr;
    vector<ListNode*> nodes;
    for (int val : lst) {
        nodes.push_back(new ListNode(val));
    }
    for (int i = 0; i < (int)nodes.size() - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    if (cyclePos != -1 && cyclePos < (int)nodes.size()) {
        nodes.back()->next = nodes[cyclePos];
    }
    return nodes[0];
}

bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    // 测试用例1: 3->2->0->-4, 尾部连接到尾节点形成环
    ListNode* head1 = listToLinkedListWithCycle({3, 2, 0, -4}, 1);
    cout << "测试1 - 链表 [3,2,0,-4] 形成环 (尾节点指向索引1):" << endl;
    cout << "  输出: " << (hasCycle(head1) ? "True" : "False") << endl;

    // 测试用例2: 1->2, 尾部连接到头节点形成环
    ListNode* head2 = listToLinkedListWithCycle({1, 2}, 0);
    cout << "\n测试2 - 链表 [1,2] 形成环 (尾节点指向头节点):" << endl;
    cout << "  输出: " << (hasCycle(head2) ? "True" : "False") << endl;

    // 测试用例3: 1, 无环
    ListNode* head3 = listToLinkedListWithCycle({1}, -1);
    cout << "\n测试3 - 链表 [1] 无环:" << endl;
    cout << "  输出: " << (hasCycle(head3) ? "True" : "False") << endl;

    return 0;
}
