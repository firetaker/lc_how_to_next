#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class RandomizedCollection {
    vector<int> vals;
    unordered_map<int, unordered_set<int>> pos;
public:
    bool insert(int val) {
        bool first = !pos.count(val) || pos[val].empty();
        pos[val].insert(vals.size());
        vals.push_back(val);
        return first;
    }
    bool remove(int val) {
        if (!pos.count(val) || pos[val].empty()) return false;
        int idx = *pos[val].begin();
        int last = vals.back();
        vals[idx] = last;
        pos[val].erase(idx);
        if (idx != (int)vals.size() - 1) {
            pos[last].insert(idx);
            pos[last].erase(vals.size() - 1);
        }
        vals.pop_back();
        return true;
    }
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

int main() {
    // 测试用例
    RandomizedCollection rc;
    cout << boolalpha << rc.insert(1) << endl;   // 预期: true
    cout << rc.remove(2) << endl;               // 预期: false
    rc.insert(2);
    cout << rc.getRandom() << endl;             // 预期: 1 或 2
    rc.remove(1);
    cout << rc.insert(2) << endl;               // 预期: false
    cout << rc.getRandom() << endl;             // 预期: 2
    return 0;
}
