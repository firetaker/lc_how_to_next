#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int height(TreeNode* node) {
    if (!node) return 0;
    int l = height(node->left);
    if (l == -1) return -1;
    int r = height(node->right);
    if (r == -1 || abs(l-r) > 1) return -1;
    return max(l, r) + 1;
}
bool isBalanced(TreeNode* root) { return height(root) != -1; }
int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left  = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left  = new TreeNode(3);
    root1->left->right = new TreeNode(3);
    cout << (isBalanced(root1) ? "True" : "False") << endl;  // False
    TreeNode* root2 = new TreeNode(1);
    root2->left  = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left  = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(9);
    cout << (isBalanced(root2) ? "True" : "False") << endl;  // True
    cout << (isBalanced(nullptr) ? "True" : "False") << endl;  // True
    return 0;
}
