#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * 1. 两数之和 (Two Sum)
 * 题目: 给定数组 nums 和目标值 target，找出和为目标值的两个数的下标。
 * 
 * 算法: 哈希表边遍历边存储
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.count(complement))
            return {seen[complement], i};
        seen[nums[i]] = i;
    }
    return {};
}

int main() {
    // 测试用例
    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> result1 = twoSum(nums1, 9);
    cout << "输入: nums=[2,7,11,15], target=9 -> 输出: [" << result1[0] << "," << result1[1] << "]" << endl;  // 预期: [0,1]
    
    vector<int> nums2 = {3, 2, 4};
    vector<int> result2 = twoSum(nums2, 6);
    cout << "输入: nums=[3,2,4], target=6 -> 输出: [" << result2[0] << "," << result2[1] << "]" << endl;  // 预期: [1,2]
    
    vector<int> nums3 = {3, 3};
    vector<int> result3 = twoSum(nums3, 6);
    cout << "输入: nums=[3,3], target=6 -> 输出: [" << result3[0] << "," << result3[1] << "]" << endl;  // 预期: [0,1]
    
    vector<int> nums4 = {1, 5, 3, 7};
    vector<int> result4 = twoSum(nums4, 10);
    cout << "输入: nums=[1,5,3,7], target=10 -> 输出: [" << result4[0] << "," << result4[1] << "]" << endl;  // 预期: [1,3]
    
    return 0;
}
