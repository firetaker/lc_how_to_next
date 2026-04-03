#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right) return root->val == targetSum;
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}
int main() {
    TreeNode* root = new TreeNode(5);
    root->left  = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left  = new TreeNode(11);
    root->right->left  = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left  = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);
    cout << (hasPathSum(root, 22) ? "True" : "False") << endl;  // True
    cout << (hasPathSum(root, 5) ? "True" : "False") << endl;   // False
    cout << (hasPathSum(new TreeNode(1), 1) ? "True" : "False") << endl;  // True
    cout << (hasPathSum(new TreeNode(1), 0) ? "True" : "False") << endl;  // False
    cout << (hasPathSum(nullptr, 0) ? "True" : "False") << endl;  // False
    return 0;
}
