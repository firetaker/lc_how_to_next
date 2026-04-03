#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val) root = root->left;
        else if (p->val > root->val && q->val > root->val) root = root->right;
        else return root;
    }
    return root;
}
int main() {
    TreeNode* root = new TreeNode(6);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left  = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left  = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left  = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    cout << lowestCommonAncestor(root, p, q)->val << endl;  // 6
    TreeNode* p2 = root->left;
    TreeNode* q2 = root->left->right;
    cout << lowestCommonAncestor(root, p2, q2)->val << endl;  // 2
    cout << (lowestCommonAncestor(nullptr, nullptr, nullptr) == nullptr ? "null" : "?") << endl;
    return 0;
}
