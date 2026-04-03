#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) result ^= num;
    return result;
}

int main() {
    // 测试用例
    vector<int> nums1 = {2, 2, 1};
    cout << singleNumber(nums1) << endl;  // 预期: 1
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << singleNumber(nums2) << endl;  // 预期: 4
    vector<int> nums3 = {1};
    cout << singleNumber(nums3) << endl;  // 预期: 1
    return 0;
}
