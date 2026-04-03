#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> idx;
    for (int i = 0; i < (int)inorder.size(); i++) idx[inorder[i]] = i;
    function<TreeNode*(int,int,int,int)> build = [&](int pl, int pr, int il, int ir) -> TreeNode* {
        if (pl > pr) return nullptr;
        TreeNode* root = new TreeNode(preorder[pl]);
        int mid = idx[preorder[pl]];
        root->left  = build(pl+1, pl+mid-il, il, mid-1);
        root->right = build(pl+mid-il+1, pr, mid+1, ir);
        return root;
    };
    return build(0, (int)preorder.size()-1, 0, (int)inorder.size()-1);
}
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}
int main() {
    vector<int> pre1 = {3, 9, 20, 15, 7};
    vector<int> in1  = {9, 3, 15, 20, 7};
    inorderPrint(buildTree(pre1, in1)); cout << endl;  // 9 3 15 20 7
    vector<int> pre2 = {1};
    vector<int> in2  = {1};
    inorderPrint(buildTree(pre2, in2)); cout << endl;  // 1
    vector<int> pre3, in3;
    cout << (buildTree(pre3, in3) == nullptr ? "null" : "?") << endl;  // null
    return 0;
}
