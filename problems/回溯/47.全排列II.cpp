#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<vector<int>>& result, vector<int>& path,
               vector<int>& nums, vector<bool>& used) {
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        // 剪枝：相同元素跳过
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
        
        used[i] = true;
        path.push_back(nums[i]);
        backtrack(result, path, nums, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());  // 排序用于去重
    backtrack(result, path, nums, used);
    return result;
}

int main() {
    // 测试用例1
    vector<int> nums1 = {1, 1, 2};
    vector<vector<int>> res1 = permuteUnique(nums1);
    cout << "Test 1: [1,1,2] - " << res1.size() << " unique permutations" << endl;
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
    vector<int> nums2 = {1, 2, 3};
    vector<vector<int>> res2 = permuteUnique(nums2);
    cout << "Test 2: [1,2,3] - " << res2.size() << " permutations" << endl;
    
    // 测试用例3
    vector<int> nums3 = {2, 2, 1, 1};
    vector<vector<int>> res3 = permuteUnique(nums3);
    cout << "Test 3: [2,2,1,1] - " << res3.size() << " unique permutations" << endl;
    
    return 0;
}
