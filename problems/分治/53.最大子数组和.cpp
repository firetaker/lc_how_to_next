#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Status {
    int sum, pref, suff, best;
};

Status combine(Status l, Status r) {
    Status res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.best = max({l.best, r.best, l.suff + r.pref});
    return res;
}

Status divideConquer(vector<int>& nums, int left, int right) {
    if (left == right) return {nums[left], nums[left], nums[left], nums[left]};
    int mid = (left + right) / 2;
    Status leftStatus = divideConquer(nums, left, mid);
    Status rightStatus = divideConquer(nums, mid+1, right);
    return combine(leftStatus, rightStatus);
}

int maxSubArrayDC(vector<int>& nums) {
    return divideConquer(nums, 0, nums.size()-1).best;
}

int main() {
    // 测试用例
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArrayDC(nums1) << endl;  // 预期: 6
    vector<int> nums2 = {1};
    cout << maxSubArrayDC(nums2) << endl;  // 预期: 1
    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << maxSubArrayDC(nums3) << endl;  // 预期: 23
    return 0;
}
