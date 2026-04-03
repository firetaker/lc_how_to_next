#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int main() {
    // 测试用例
    vector<int> n1 = {4, 5, 6, 7, 0, 1, 2};
    cout << search(n1, 0) << endl;  // 预期: 4
    cout << search(n1, 3) << endl;  // 预期: -1

    vector<int> n2 = {1};
    cout << search(n2, 0) << endl;  // 预期: -1

    return 0;
}
