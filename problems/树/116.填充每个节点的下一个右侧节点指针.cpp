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
    if (root->left)  root->left->next = root->right;
    if (root->next && root->right) root->right->next = root->next->left;
    connect(root->left);
    connect(root->right);
    return root;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left  = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left  = new TreeNode(6);
    root->right->right = new TreeNode(7);
    connect(root);
    cout << root->left->next->val << endl;         // 3
    cout << root->left->left->next->val << endl;   // 5
    cout << root->right->left->next->val << endl;  // 7
    cout << (connect(nullptr) == nullptr ? "null" : "?") << endl;  // null
    return 0;
}
