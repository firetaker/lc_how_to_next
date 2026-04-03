#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    bool rev = false;
    while (!q.empty()) {
        int sz = q.size();
        vector<int> level;
        while (sz--) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        if (rev) reverse(level.begin(), level.end());
        result.push_back(level);
        rev = !rev;
    }
    return result;
}
int main() {
    TreeNode* root = new TreeNode(3);
    root->left  = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left  = new TreeNode(15);
    root->right->right = new TreeNode(7);
    auto r = zigzagLevelOrder(root);
    for (auto& lv : r) { for (int v : lv) cout << v << " "; cout << endl; }
    // [[3], [20, 9], [15, 7]]
    r = zigzagLevelOrder(new TreeNode(1));
    for (int v : r[0]) cout << v << " "; cout << endl;  // 1
    cout << zigzagLevelOrder(nullptr).size() << endl;  // 0
    return 0;
}
