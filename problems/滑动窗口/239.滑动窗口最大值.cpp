#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (dq.front() <= i - k)
            dq.pop_front();
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }
    return result;
}

int main() {
    // 测试用例
    vector<int> n1 = {1, 3, -1, -3, 5, 3, 6, 7};
    auto r1 = maxSlidingWindow(n1, 3);
    for (int x : r1) cout << x << " ";
    cout << endl;  // 预期: 3 3 5 5 6 7

    vector<int> n2 = {1};
    auto r2 = maxSlidingWindow(n2, 1);
    for (int x : r2) cout << x << " ";
    cout << endl;  // 预期: 1

    vector<int> n3 = {1, -1};
    auto r3 = maxSlidingWindow(n3, 1);
    for (int x : r3) cout << x << " ";
    cout << endl;  // 预期: 1 -1

    return 0;
}
