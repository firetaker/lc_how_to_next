#include <iostream>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxPathSum(TreeNode* root) {
    int result = INT_MIN;
    function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
        if (!node) return 0;
        int l = max(0, dfs(node->left));
        int r = max(0, dfs(node->right));
        result = max(result, l + r + node->val);
        return max(l, r) + node->val;
    };
    dfs(root);
    return result;
}
int main() {
    TreeNode* root = new TreeNode(-10);
    root->left  = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left  = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << maxPathSum(root) << endl;       // 42
    cout << maxPathSum(new TreeNode(1)) << endl;  // 1
    cout << maxPathSum(nullptr) << endl;          // 0
    return 0;
}
