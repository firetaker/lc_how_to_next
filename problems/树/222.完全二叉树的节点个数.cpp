#include <iostream>
#include <cmath>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countNodes(TreeNode* root) {
    if (!root) return 0;
    TreeNode *l = root, *r = root;
    int hl = 0, hr = 0;
    while (l) { hl++; l = l->left; }
    while (r) { hr++; r = r->right; }
    if (hl == hr) return (1 << hl) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left  = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left  = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << countNodes(root) << endl;       // 7
    cout << countNodes(new TreeNode(1)) << endl;  // 1
    cout << countNodes(nullptr) << endl;          // 0
    return 0;
}
