#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top(); st.pop();
        result.push_back(node->val);
        if (node->right) st.push(node->right);
        if (node->left)  st.push(node->left);
    }
    return result;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    for (int v : preorderTraversal(root)) cout << v << " "; cout << endl;  // 1 2 3
    for (int v : preorderTraversal(new TreeNode(1))) cout << v << " "; cout << endl;  // 1
    for (int v : preorderTraversal(nullptr)) cout << v << " "; cout << endl;  // (empty)
    return 0;
}
