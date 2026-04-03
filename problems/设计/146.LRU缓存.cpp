#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
    int capacity;
    list<pair<int, int>> lst;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int c) : capacity(c) {}

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        lst.splice(lst.begin(), lst, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            lst.splice(lst.begin(), lst, mp[key]);
        } else {
            lst.push_front({key, value});
            mp[key] = lst.begin();
            if (lst.size() > capacity) {
                mp.erase(lst.back().first);
                lst.pop_back();
            }
        }
    }
};

int main() {
    // 测试用例
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;  // 预期: 1
    cache.put(3, 3);               // 淘汰 key=2
    cout << cache.get(2) << endl;  // 预期: -1
    cache.put(4, 4);               // 淘汰 key=1
    cout << cache.get(1) << endl;  // 预期: -1
    cout << cache.get(3) << endl;  // 预期: 3
    cout << cache.get(4) << endl;  // 预期: 4
    return 0;
}
