#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}
int main() {
    TreeNode* root = new TreeNode(4);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left  = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left  = new TreeNode(6);
    root->right->right = new TreeNode(9);
    inorderPrint(invertTree(root)); cout << endl;  // 9 7 6 4 3 2 1
    inorderPrint(invertTree(new TreeNode(1))); cout << endl;  // 1
    cout << (invertTree(nullptr) == nullptr ? "null" : "?") << endl;  // null
    return 0;
}
