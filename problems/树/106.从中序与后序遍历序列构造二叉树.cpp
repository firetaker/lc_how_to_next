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

TreeNode* buildTreeInPost(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> idx;
    for (int i = 0; i < (int)inorder.size(); i++) idx[inorder[i]] = i;
    function<TreeNode*(int,int,int)> build = [&](int il, int ir, int pl) -> TreeNode* {
        if (il > ir) return nullptr;
        TreeNode* root = new TreeNode(postorder[pl]);
        int mid = idx[postorder[pl]];
        root->left  = build(il, mid-1, pl-(ir-mid)-1);
        root->right = build(mid+1, ir, pl-1);
        return root;
    };
    return build(0, (int)inorder.size()-1, (int)postorder.size()-1);
}
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}
int main() {
    vector<int> in1  = {9, 3, 15, 20, 7};
    vector<int> post1 = {9, 15, 7, 20, 3};
    inorderPrint(buildTreeInPost(in1, post1)); cout << endl;  // 9 3 15 20 7
    vector<int> in2  = {1};
    vector<int> post2 = {1};
    inorderPrint(buildTreeInPost(in2, post2)); cout << endl;  // 1
    vector<int> in3, post3;
    cout << (buildTreeInPost(in3, post3) == nullptr ? "null" : "?") << endl;  // null
    return 0;
}
