#include <iostream>
using namespace std;

long long computeArea(int ax1, int ay1, int ax2, int ay2,
                     int bx1, int by1, int bx2, int by2) {
    long long area1 = 1LL*(ax2-ax1)*(ay2-ay1);
    long long area2 = 1LL*(bx2-bx1)*(by2-by1);
    long long overlap = max(0, min(ax2,bx2)-max(ax1,bx1)) * max(0, min(ay2,by2)-max(ay1,by1));
    return area1 + area2 - overlap;
}

int main() {
    // 测试用例
    cout << computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;      // 预期: 45
    cout << computeArea(0, 0, 0, 0, -1, -1, 1, 1) << endl;      // 预期: 4
    cout << computeArea(-2, -2, 2, 2, -4, -4, 0, 0) << endl;    // 预期: 20
    return 0;
}
