#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseWords(vector<char>& s) {
    reverse(s.begin(), s.end());
    int i = 0;
    for (int j = 0; j <= s.size(); j++) {
        if (j == s.size() || s[j] == ' ') {
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
    }
}

int main() {
    // 测试用例
    vector<char> t1 = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    reverseWords(t1);
    for (char c : t1) cout << c;
    cout << endl;  // 预期: blue is sky the

    vector<char> t2 = {' ', ' ', 'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', ' ', ' '};
    reverseWords(t2);
    for (char c : t2) cout << c;
    cout << endl;  // 预期: world hello
    return 0;
}
