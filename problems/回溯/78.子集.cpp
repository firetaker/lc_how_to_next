#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<vector<int>>& result, vector<int>& path, 
               vector<int>& nums, int start) {
    result.push_back(path);
    for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtrack(result, path, nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    backtrack(result, path, nums, 0);
    return result;
}

int main() {
    // 测试用例1
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> res1 = subsets(nums1);
    cout << "Test 1: [1,2,3]" << endl;
    for (auto& subset : res1) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;
    
    // 测试用例2
    vector<int> nums2 = {0};
    vector<vector<int>> res2 = subsets(nums2);
    cout << "Test 2: [0]" << endl;
    for (auto& subset : res2) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;
    
    // 测试用例3
    vector<int> nums3 = {1, 2, 3, 4};
    vector<vector<int>> res3 = subsets(nums3);
    cout << "Test 3: [1,2,3,4] - " << res3.size() << " subsets" << endl;
    
    return 0;
}
