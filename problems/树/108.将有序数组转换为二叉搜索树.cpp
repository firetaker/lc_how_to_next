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

TreeNode* sortedArrayToBST(vector<int>& nums) {
    function<TreeNode*(int,int)> build = [&](int l, int r) -> TreeNode* {
        if (l > r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left  = build(l, mid-1);
        root->right = build(mid+1, r);
        return root;
    };
    return build(0, (int)nums.size()-1);
}
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}
int main() {
    vector<int> nums1 = {-10, -3, 0, 5, 9};
    inorderPrint(sortedArrayToBST(nums1)); cout << endl;  // -10 -3 0 5 9
    vector<int> nums2 = {1, 3};
    inorderPrint(sortedArrayToBST(nums2)); cout << endl;  // 1 3
    vector<int> nums3;
    cout << (sortedArrayToBST(nums3) == nullptr ? "null" : "?") << endl;  // null
    return 0;
}
