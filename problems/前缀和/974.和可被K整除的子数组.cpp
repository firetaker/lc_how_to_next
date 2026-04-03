#include <iostream>
#include <vector>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    vector<int> modCount(k, 0);
    modCount[0] = 1;
    int prefixMod = 0, count = 0;
    for (int num : nums) {
        prefixMod = (prefixMod + num) % k;
        if (prefixMod < 0) prefixMod += k;
        count += modCount[prefixMod];
        modCount[prefixMod]++;
    }
    return count;
}

int main() {
    // 测试用例
    vector<int> nums1 = {4, 5, 0, -2, -3, 1};
    cout << subarraysDivByK(nums1, 5) << endl;
    // 预期: 7

    vector<int> nums2 = {5};
    cout << subarraysDivByK(nums2, 9) << endl;
    // 预期: 0

    vector<int> nums3 = {-1, 2, 9};
    cout << subarraysDivByK(nums3, 2) << endl;
    // 预期: 2

    return 0;
}
