#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 15. 三数之和 (3Sum)
//
// 题目: 给你一个整数数组 nums，判断是否存在三元组 [nums[i], nums[j], nums[k]]
//       满足 i != j、i != k 且 j != k，同时满足 nums[i] + nums[j] + nums[k] == 0。
//       返回所有满足条件的三元组（不可重复）。
//
// 算法: 排序 + 双指针
//       - 先对数组排序
//       - 固定指针 i，然后在 i+1 到 n-1 之间用双指针 left, right
//       - 若三数之和为 0，记录并移动指针去重
//       - 时间复杂度 O(n²)，空间复杂度 O(1)

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int s = nums[i] + nums[left] + nums[right];
            if (s < 0) left++;
            else if (s > 0) right--;
            else {
                result.push_back({nums[i], nums[left], nums[right]});
                left++; right--;
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            }
        }
    }
    return result;
}

int main() {
    // 测试用例1: 标准情况
    vector<int> t1 = {-1, 0, 1, 2, -1, -4};
    auto r1 = threeSum(t1);
    cout << "[-1,0,1,2,-1,-4] -> [";
    for (auto& tri : r1) {
        cout << "[" << tri[0] << "," << tri[1] << "," << tri[2] << "]";
        if (&tri != &r1.back()) cout << ",";
    }
    cout << "]" << endl;  // 预期: [[-1,-1,2],[-1,0,1]]

    // 测试用例2: 无解情况
    vector<int> t2 = {0, 1, 1};
    auto r2 = threeSum(t2);
    cout << "[0,1,1] -> " << (r2.empty() ? "[]" : "has results") << endl;  // 预期: []

    // 测试用例3: 全零情况
    vector<int> t3 = {0, 0, 0};
    auto r3 = threeSum(t3);
    cout << "[0,0,0] -> [";
    for (auto& tri : r3) {
        cout << "[" << tri[0] << "," << tri[1] << "," << tri[2] << "]";
    }
    cout << "]" << endl;  // 预期: [[0,0,0]]

    return 0;
}
