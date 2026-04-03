#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    int total = 0;
    if (root->left && !root->left->left && !root->left->right) total += root->left->val;
    else total += sumOfLeftLeaves(root->left);
    total += sumOfLeftLeaves(root->right);
    return total;
}
int main() {
    TreeNode* root = new TreeNode(3);
    root->left  = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left  = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left  = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << sumOfLeftLeaves(root) << endl;       // 24
    cout << sumOfLeftLeaves(new TreeNode(1)) << endl;  // 0
    cout << sumOfLeftLeaves(nullptr) << endl;           // 0
    return 0;
}
