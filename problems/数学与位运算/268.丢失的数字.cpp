#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int res = nums.size();
    for (int i = 0; i < (int)nums.size(); i++) res ^= i ^ nums[i];
    return res;
}

int main() {
    // 测试用例
    vector<int> nums1 = {3, 0, 1};
    cout << missingNumber(nums1) << endl;  // 预期: 2
    vector<int> nums2 = {0, 1};
    cout << missingNumber(nums2) << endl;  // 预期: 2
    vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << missingNumber(nums3) << endl;  // 预期: 8
    return 0;
}
