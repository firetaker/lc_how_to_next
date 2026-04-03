#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class RandomizedSet {
    vector<int> vals;
    unordered_map<int, int> pos;
public:
    bool insert(int val) {
        if (pos.count(val)) return false;
        pos[val] = vals.size();
        vals.push_back(val);
        return true;
    }
    bool remove(int val) {
        if (!pos.count(val)) return false;
        int idx = pos[val], last = vals.back();
        vals[idx] = last;
        pos[last] = idx;
        vals.pop_back();
        pos.erase(val);
        return true;
    }
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

int main() {
    // 测试用例
    RandomizedSet rs;
    cout << boolalpha << rs.insert(1) << endl;   // 预期: true
    cout << rs.remove(2) << endl;                 // 预期: false
    cout << rs.insert(2) << endl;                 // 预期: true
    cout << rs.getRandom() << endl;               // 预期: 1 或 2
    rs.remove(1);
    cout << rs.insert(2) << endl;                // 预期: false
    cout << rs.getRandom() << endl;               // 预期: 2
    return 0;
}
