#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixIndex;
    prefixIndex[0] = -1;
    int prefix = 0;
    for (int i = 0; i < nums.size(); i++) {
        prefix = (prefix + nums[i]) % k;
        if (prefixIndex.count(prefix)) {
            if (i - prefixIndex[prefix] > 1) return true;
        } else {
            prefixIndex[prefix] = i;
        }
    }
    return false;
}

int main() {
    // 测试用例
    vector<int> nums1 = {23, 2, 4, 6, 7};
    cout << (checkSubarraySum(nums1, 6) ? "True" : "False") << endl;
    // 预期: True

    vector<int> nums2 = {23, 2, 6, 4, 7};
    cout << (checkSubarraySum(nums2, 6) ? "True" : "False") << endl;
    // 预期: True

    vector<int> nums3 = {23, 2, 6, 4, 7};
    cout << (checkSubarraySum(nums3, 13) ? "True" : "False") << endl;
    // 预期: False

    return 0;
}
