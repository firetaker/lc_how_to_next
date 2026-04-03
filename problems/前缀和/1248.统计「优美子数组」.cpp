#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int prefix = 0, count = 0;
    for (int num : nums) {
        prefix += num & 1;
        count += prefixCount[prefix - k];
        prefixCount[prefix]++;
    }
    return count;
}

int main() {
    // 测试用例
    vector<int> nums1 = {1, 1, 2, 1, 1};
    cout << numberOfSubarrays(nums1, 3) << endl;
    // 预期: 2

    vector<int> nums2 = {2, 4, 6};
    cout << numberOfSubarrays(nums2, 1) << endl;
    // 预期: 0

    vector<int> nums3 = {2, 2, 2, 1, 2, 2, 1, 2};
    cout << numberOfSubarrays(nums3, 2) << endl;
    // 预期: 16

    return 0;
}
