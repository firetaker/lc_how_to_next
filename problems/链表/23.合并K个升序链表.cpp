#include <iostream>
#include <vector>
#include <queue>
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

struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*> lists) {
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
    for (auto node : lists) {
        if (node) pq.push(node);
    }
    
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        cur->next = node;
        cur = cur->next;
        if (node->next) {
            pq.push(node->next);
        }
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
    // 测试用例1: [[1,4,5],[1,3,4],[2,6]] 合并为 [1,1,2,3,4,4,5,6]
    vector<ListNode*> lists1 = {
        listToLinkedList({1, 4, 5}),
        listToLinkedList({1, 3, 4}),
        listToLinkedList({2, 6})
    };
    ListNode* result = mergeKLists(lists1);
    cout << "测试1 - 合并 [[1,4,5],[1,3,4],[2,6]]:" << endl;
    cout << "  输出: ";
    printList(result);
    cout << endl;

    // 测试用例2: [[], [1]] 合并为 [1]
    vector<ListNode*> lists2 = {nullptr, listToLinkedList({1})};
    result = mergeKLists(lists2);
    cout << "\n测试2 - 合并 [[], [1]]:" << endl;
    cout << "  输出: ";
    printList(result);
    cout << endl;

    // 测试用例3: [[1,2,3],[4,5,6]] 合并为 [1,2,3,4,5,6]
    vector<ListNode*> lists3 = {
        listToLinkedList({1, 2, 3}),
        listToLinkedList({4, 5, 6})
    };
    result = mergeKLists(lists3);
    cout << "\n测试3 - 合并 [[1,2,3],[4,5,6]]:" << endl;
    cout << "  输出: ";
    printList(result);
    cout << endl;

    return 0;
}
