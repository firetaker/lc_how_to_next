#include <iostream>
#include <functional>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) return new TreeNode(head->val);
    ListNode *slow = head, *fast = head, *prev = nullptr;
    while (fast && fast->next) {
        prev = slow; slow = slow->next; fast = fast->next->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    if (prev) { prev->next = nullptr; root->left = sortedListToBST(head); }
    root->right = sortedListToBST(slow->next);
    return root;
}
int main() {
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    TreeNode* root = sortedListToBST(head);
    cout << root->val << endl;  // 0
    cout << (sortedListToBST(nullptr) == nullptr ? "null" : "?") << endl;  // null
    return 0;
}
