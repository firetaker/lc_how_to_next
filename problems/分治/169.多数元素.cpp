#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0, candidate = 0;
    for (int num : nums) {
        if (count == 0) candidate = num;
        count += (num == candidate ? 1 : -1);
    }
    return candidate;
}

int main() {
    // 测试用例
    vector<int> nums1 = {3, 2, 3};
    cout << majorityElement(nums1) << endl;  // 预期: 3
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums2) << endl;  // 预期: 2
    vector<int> nums3 = {1};
    cout << majorityElement(nums3) << endl;  // 预期: 1
    return 0;
}
