#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; i++) pq.pop();
    return pq.top();
}

int main() {
    // 测试用例
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    cout << findKthLargest(nums1, 2) << endl;  // 预期: 5
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << findKthLargest(nums2, 4) << endl;  // 预期: 4
    vector<int> nums3 = {1};
    cout << findKthLargest(nums3, 1) << endl;  // 预期: 1
    return 0;
}
