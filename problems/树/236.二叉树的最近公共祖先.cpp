#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left  = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}
int main() {
    TreeNode* root = new TreeNode(3);
    root->left  = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left  = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left  = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left  = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    TreeNode* p = root->left;
    TreeNode* q = root->left->right->right;
    cout << lowestCommonAncestor(root, p, q)->val << endl;  // 5
    TreeNode* p2 = root->left->right;
    TreeNode* q2 = root->right;
    cout << lowestCommonAncestor(root, p2, q2)->val << endl;  // 3
    cout << (lowestCommonAncestor(nullptr, nullptr, nullptr) == nullptr ? "null" : "?") << endl;
    return 0;
}
