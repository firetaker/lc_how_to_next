#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int prefix = 0, count = 0;
    for (int num : nums) {
        prefix += num;
        count += prefixCount[prefix - k];
        prefixCount[prefix]++;
    }
    return count;
}

int main() {
    // 测试用例
    vector<int> nums1 = {1, 1, 1};
    cout << subarraySum(nums1, 2) << endl;
    // 预期: 2

    vector<int> nums2 = {1, 2, 3};
    cout << subarraySum(nums2, 3) << endl;
    // 预期: 2

    vector<int> nums3 = {3, 4, 7, 2, -3, 1, 4, 2};
    cout << subarraySum(nums3, 7) << endl;
    // 预期: 4

    return 0;
}
