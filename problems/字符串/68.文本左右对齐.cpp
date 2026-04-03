#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int i = 0;
    while (i < words.size()) {
        int j = i + 1, lineLen = words[i].size();
        while (j < words.size() && lineLen + 1 + words[j].size() <= maxWidth)
            lineLen += 1 + words[j++].size();

        int spaces = maxWidth - lineLen, cnt = j - i - 1;
        string line = words[i];
        for (int k = 1; k < j - i; k++) {
            int sp = cnt > 0 ? spaces / cnt : spaces;
            line += string(sp + 1, ' ') + words[i + k];
            spaces -= sp;
            cnt--;
        }
        if (cnt == 0) line += string(maxWidth - line.size(), ' ');
        result.push_back(line);
        i = j;
    }
    return result;
}

int main() {
    // 测试用例
    vector<string> t1 = {"This", "is", "an", "example", "of", "text", "justification."};
    auto r1 = fullJustify(t1, 16);
    for (auto& line : r1) cout << "'" << line << "'" << endl;

    cout << "---" << endl;
    vector<string> t2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    auto r2 = fullJustify(t2, 16);
    for (auto& line : r2) cout << "'" << line << "'" << endl;
    return 0;
}
