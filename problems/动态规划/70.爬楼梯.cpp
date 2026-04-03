#include <iostream>
#include <vector>
using namespace std;

/**
 * 70. 爬楼梯 (Climbing Stairs)
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。有多少种不同的方法可以爬到楼顶？
 *
 * 动态规划思路：
 * - dp[i] 表示爬到第 i 阶的方法数
 * - dp[i] = dp[i-1] + dp[i-2]
 * - 初始条件: dp[1]=1, dp[2]=2
 */
int climbStairs(int n) {
    if (n <= 2) return n;

    int prev2 = 1;  // dp[i-2]
    int prev1 = 2;  // dp[i-1]

    for (int i = 3; i <= n; i++) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {
    // 测试用例1: n=2
    assert(climbStairs(2) == 2);
    cout << "测试1通过: n=2 -> 2" << endl;

    // 测试用例2: n=3
    assert(climbStairs(3) == 3);
    cout << "测试2通过: n=3 -> 3" << endl;

    // 测试用例3: n=5
    assert(climbStairs(5) == 8);
    cout << "测试3通过: n=5 -> 8" << endl;

    cout << "所有测试用例通过!" << endl;
    return 0;
}
