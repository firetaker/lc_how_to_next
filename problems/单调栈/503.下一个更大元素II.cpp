#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;
    for (int i = 0; i < 2 * n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i % n]) {
            result[st.top()] = nums[i % n];
            st.pop();
        }
        if (i < n) st.push(i);
    }
    return result;
}

int main() {
    // 测试用例
    vector<int> nums1 = {1, 2, 1};
    auto res1 = nextGreaterElements(nums1);
    for (int x : res1) cout << x << " ";
    cout << endl;
    // 预期: 2 -1 2

    vector<int> nums2 = {1, 2, 3, 4, 3};
    auto res2 = nextGreaterElements(nums2);
    for (int x : res2) cout << x << " ";
    cout << endl;
    // 预期: 2 3 4 -1 4

    vector<int> nums3 = {5, 4, 3, 2, 1};
    auto res3 = nextGreaterElements(nums3);
    for (int x : res3) cout << x << " ";
    cout << endl;
    // 预期: -1 5 5 5 5

    return 0;
}
