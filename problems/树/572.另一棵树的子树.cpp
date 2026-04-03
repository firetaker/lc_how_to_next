#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return a->val == b->val && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;
    if (isSameTree(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
int main() {
    TreeNode* root = new TreeNode(3);
    root->left  = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left  = new TreeNode(1);
    root->left->right = new TreeNode(2);
    TreeNode* sub = new TreeNode(4);
    sub->left  = new TreeNode(1);
    sub->right = new TreeNode(2);
    cout << (isSubtree(root, sub) ? "True" : "False") << endl;  // True
    TreeNode* sub2 = new TreeNode(3);
    sub2->left  = new TreeNode(1);
    sub2->right = new TreeNode(2);
    cout << (isSubtree(root, sub2) ? "True" : "False") << endl;  // False
    cout << (isSubtree(nullptr, nullptr) ? "True" : "False") << endl;  // False
    return 0;
}
