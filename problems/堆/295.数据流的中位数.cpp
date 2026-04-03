#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
public:
    void addNum(int num) {
        small.push(num);
        large.push(small.top()); small.pop();
        if (small.size() < large.size()) {
            small.push(large.top()); large.pop();
        }
    }
    double findMedian() {
        return small.size() > large.size() ? small.top() : (small.top() + large.top()) / 2.0;
    }
};

int main() {
    // 测试用例
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl;  // 预期: 1.5
    mf.addNum(3);
    cout << mf.findMedian() << endl;  // 预期: 2.0
    MedianFinder mf2;
    mf2.addNum(2);
    mf2.addNum(3);
    mf2.addNum(4);
    cout << mf2.findMedian() << endl;  // 预期: 3.0
    return 0;
}
