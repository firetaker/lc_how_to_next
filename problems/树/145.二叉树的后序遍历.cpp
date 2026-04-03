#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<pair<TreeNode*, bool>> st;
    if (root) st.push({root, false});
    while (!st.empty()) {
        auto [node, visited] = st.top(); st.pop();
        if (visited) {
            result.push_back(node->val);
        } else {
            st.push({node, true});
            if (node->right) st.push({node->right, false});
            if (node->left)  st.push({node->left, false});
        }
    }
    return result;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    for (int v : postorderTraversal(root)) cout << v << " "; cout << endl;  // 3 2 1
    for (int v : postorderTraversal(new TreeNode(1))) cout << v << " "; cout << endl;  // 1
    for (int v : postorderTraversal(nullptr)) cout << v << " "; cout << endl;  // (empty)
    return 0;
}
