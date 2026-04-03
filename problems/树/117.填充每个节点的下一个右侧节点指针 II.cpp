#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

TreeNode* connect(TreeNode* root) {
    if (!root) return root;
    TreeNode* dummy = new TreeNode(0);
    TreeNode* cur = dummy;
    while (root) {
        if (root->left) { cur->next = root->left; cur = cur->next; }
        if (root->right) { cur->next = root->right; cur = cur->next; }
        root = root->next;
        if (!root) { cur = dummy; root = dummy->next; dummy->next = nullptr; }
    }
    return dummy;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    TreeNode* res = connect(root);
    cout << res->val << endl;  // 1
    cout << (connect(nullptr) == nullptr ? "null" : "?") << endl;  // null
    return 0;
}
