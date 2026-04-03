#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int leftmost;
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        leftmost = node->val;
        if (node->right) q.push(node->right);
        if (node->left)  q.push(node->left);
    }
    return leftmost;
}
int main() {
    TreeNode* root = new TreeNode(2);
    root->left  = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << findBottomLeftValue(root) << endl;  // 1
    TreeNode* root2 = new TreeNode(1);
    root2->left  = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left  = new TreeNode(4);
    root2->right->left  = new TreeNode(6);
    root2->right->right = new TreeNode(7);
    root2->right->right->left = new TreeNode(9);
    cout << findBottomLeftValue(root2) << endl;  // 9
    cout << findBottomLeftValue(new TreeNode(1)) << endl;  // 1
    return 0;
}
