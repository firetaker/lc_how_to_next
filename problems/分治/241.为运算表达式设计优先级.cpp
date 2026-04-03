#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> diffWaysToCompute(string expression) {
    if (expression.find('+') == string::npos && expression.find('-') == string::npos && expression.find('*') == string::npos)
        return {stoi(expression)};
    vector<int> result;
    for (int i = 0; i < (int)expression.size(); i++) {
        char op = expression[i];
        if (op == '+' || op == '-' || op == '*') {
            auto left = diffWaysToCompute(expression.substr(0, i));
            auto right = diffWaysToCompute(expression.substr(i+1));
            for (int l : left)
                for (int r : right)
                    result.push_back(op == '+' ? l+r : op == '-' ? l-r : l*r);
        }
    }
    return result;
}

int main() {
    // 测试用例
    auto r1 = diffWaysToCompute("2-1-1");
    for (int x : r1) cout << x << " "; cout << endl;  // 预期: 0 2
    auto r2 = diffWaysToCompute("2*3-4*5");
    for (int x : r2) cout << x << " "; cout << endl;  // 预期: -34 -14 -10 -10 10
    auto r3 = diffWaysToCompute("1+1");
    for (int x : r3) cout << x << " "; cout << endl;  // 预期: 2
    return 0;
}
