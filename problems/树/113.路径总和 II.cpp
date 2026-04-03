#include <iostream>
#include <vector>
#include <functional>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> result;
    vector<int> path;
    function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int rem) {
        if (!node) return;
        path.push_back(node->val);
        if (!node->left && !node->right && rem == node->val) result.push_back(path);
        dfs(node->left, rem - node->val);
        dfs(node->right, rem - node->val);
        path.pop_back();
    };
    dfs(root, targetSum);
    return result;
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
    auto r = pathSum(root, 22);
    for (auto& p : r) { for (int v : p) cout << v << " "; cout << endl; }
    // 5 4 11 2 / 5 8 4 1
    r = pathSum(new TreeNode(1), 1);
    for (int v : r[0]) cout << v << " "; cout << endl;  // 1
    cout << pathSum(nullptr, 0).size() << endl;  // 0
    return 0;
}
