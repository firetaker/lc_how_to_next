#include <iostream>
#include <vector>
using namespace std;

int singleNumberII(vector<int>& nums) {
    int seen_once = 0, seen_twice = 0;
    for (int num : nums) {
        seen_once = (seen_once ^ num) & ~seen_twice;
        seen_twice = (seen_twice ^ num) & ~seen_once;
    }
    return seen_once;
}

int main() {
    // 测试用例
    vector<int> nums1 = {2, 2, 3, 2};
    cout << singleNumberII(nums1) << endl;  // 预期: 3
    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};
    cout << singleNumberII(nums2) << endl;  // 预期: 99
    vector<int> nums3 = {-2, -2, -1, -2, -1, -1};
    cout << singleNumberII(nums3) << endl;  // 预期: -1
    return 0;
}
