#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<vector<int>>& result, vector<int>& path,
               vector<int>& nums, vector<bool>& used) {
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        path.push_back(nums[i]);
        backtrack(result, path, nums, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    backtrack(result, path, nums, used);
    return result;
}

int main() {
    // 测试用例1
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> res1 = permute(nums1);
    cout << "Test 1: [1,2,3] - " << res1.size() << " permutations" << endl;
    for (auto& perm : res1) {
        cout << "[";
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i];
            if (i < perm.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;
    
    // 测试用例2
    vector<int> nums2 = {0, 1};
    vector<vector<int>> res2 = permute(nums2);
    cout << "Test 2: [0,1] - " << res2.size() << " permutations" << endl;
    
    // 测试用例3
    vector<int> nums3 = {1};
    vector<vector<int>> res3 = permute(nums3);
    cout << "Test 3: [1] - " << res3.size() << " permutation" << endl;
    
    return 0;
}
