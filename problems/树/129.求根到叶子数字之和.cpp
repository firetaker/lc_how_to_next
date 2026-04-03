#include <iostream>
#include <functional>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumNumbers(TreeNode* root) {
    int result = 0;
    function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int num) {
        if (!node) return;
        num = num * 10 + node->val;
        if (!node->left && !node->right) { result += num; return; }
        dfs(node->left, num);
        dfs(node->right, num);
    };
    dfs(root, 0);
    return result;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << sumNumbers(root) << endl;             // 25
    cout << sumNumbers(new TreeNode(5)) << endl;   // 5
    cout << sumNumbers(nullptr) << endl;           // 0
    return 0;
}
