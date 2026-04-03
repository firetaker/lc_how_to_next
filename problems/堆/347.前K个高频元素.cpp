#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    priority_queue<pair<int,int>> pq;
    for (auto& kv : freq) pq.push({kv.second, kv.first});
    vector<int> result;
    while (k-- > 0) { result.push_back(pq.top().second); pq.pop(); }
    return result;
}

int main() {
    // 测试用例
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    auto res1 = topKFrequent(nums1, 2);
    for (int x : res1) cout << x << " "; cout << endl;  // 预期: 1 2
    vector<int> nums2 = {1};
    auto res2 = topKFrequent(nums2, 1);
    for (int x : res2) cout << x << " "; cout << endl;  // 预期: 1
    vector<int> nums3 = {4, 4, 4, 6, 6, 6, 6, 1, 2};
    auto res3 = topKFrequent(nums3, 2);
    for (int x : res3) cout << x << " "; cout << endl;  // 预期: 6 4
    return 0;
}
