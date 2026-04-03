#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1) return t2;
    if (!t2) return t1;
    t1->val += t2->val;
    t1->left  = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}
int main() {
    TreeNode* t1 = new TreeNode(1);
    t1->left  = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(5);
    TreeNode* t2 = new TreeNode(2);
    t2->left  = new TreeNode(1);
    t2->right = new TreeNode(3);
    t2->left->right = new TreeNode(4);
    t2->right->right = new TreeNode(7);
    inorderPrint(mergeTrees(t1, t2)); cout << endl;  // 5 4 4 3 5 7
    inorderPrint(mergeTrees(new TreeNode(1), nullptr)); cout << endl;  // 1
    cout << (mergeTrees(nullptr, nullptr) == nullptr ? "null" : "?") << endl;  // null
    return 0;
}
