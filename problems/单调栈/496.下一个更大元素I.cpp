#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    unordered_map<int, int> ng;
    for (int num : nums2) {
        while (!st.empty() && st.top() < num) {
            ng[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }
    vector<int> result;
    for (int num : nums1) result.push_back(ng.count(num) ? ng[num] : -1);
    return result;
}

int main() {
    // 测试用例
    vector<int> nums1_1 = {4, 1, 2}, nums2_1 = {1, 3, 4, 2};
    auto res1 = nextGreaterElement(nums1_1, nums2_1);
    for (int x : res1) cout << x << " ";
    cout << endl;
    // 预期: -1 3 -1

    vector<int> nums1_2 = {2, 4}, nums2_2 = {1, 2, 3, 4};
    auto res2 = nextGreaterElement(nums1_2, nums2_2);
    for (int x : res2) cout << x << " ";
    cout << endl;
    // 预期: 3 -1

    vector<int> nums1_3 = {1, 3, 5, 2, 4}, nums2_3 = {6, 5, 4, 3, 2, 1, 7};
    auto res3 = nextGreaterElement(nums1_3, nums2_3);
    for (int x : res3) cout << x << " ";
    cout << endl;
    // 预期: 7 7 7 7 7

    return 0;
}
