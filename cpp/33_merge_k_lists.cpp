/**
 * LeetCode #23: 合并K个升序链表
 * 题目: 合并 K 个升序链表为一个升序链表。
 * 解法: 最小堆（优先队列）- 初始将每个链表头节点入堆，
 *       每次弹出堆顶（最小节点）并将其下一节点入堆。
 * 时间 O(N log K)，N 为总节点数，K 为链表数量。
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x=0, ListNode* n=nullptr) : val(x), next(n) {}
};

class Solution {
public:
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val; // 小顶堆
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
        for (auto node : lists)
            if (node) heap.push(node);
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!heap.empty()) {
            ListNode* cur = heap.top(); heap.pop();
            tail->next = cur;
            tail = tail->next;
            if (cur->next) heap.push(cur->next);
        }
        return dummy.next;
    }
};

int main() {
    Solution sol;
    ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *l3 = new ListNode(2, new ListNode(6));
    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* res = sol.mergeKLists(lists);
    while (res) { cout << res->val << " "; res = res->next; } // 1 1 2 3 4 4 5 6
    cout << endl;
    return 0;
}
