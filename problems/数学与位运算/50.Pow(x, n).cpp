#include <iostream>
#include <cmath>
using namespace std;

double myPow(double x, long long n) {
    if (n < 0) { x = 1/x; n = -n; }
    double result = 1.0, cur = x;
    while (n) {
        if (n % 2 == 1) result *= cur;
        cur *= cur;
        n /= 2;
    }
    return result;
}

int main() {
    // 测试用例
    cout << myPow(2.0, 10) << endl;   // 预期: 1024
    cout << myPow(2.1, 3) << endl;   // 预期: 9.261
    cout << myPow(2.0, -2) << endl;  // 预期: 0.25
    cout << myPow(0.0, 1) << endl;   // 预期: 0
    return 0;
}
