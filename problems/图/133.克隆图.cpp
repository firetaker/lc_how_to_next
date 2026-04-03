#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors(vector<Node*>()) {}
    Node(int x) : val(x), neighbors(vector<Node*>()) {}
    Node(int x, vector<Node*> n) : val(x), neighbors(n) {}
};

unordered_map<Node*, Node*> mp;

Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    if (mp.count(node)) return mp[node];
    Node* clone = new Node(node->val);
    mp[node] = clone;
    for (Node* n : node->neighbors)
        clone->neighbors.push_back(cloneGraph(n));
    return clone;
}

int main() {
    // 测试用例
    // 构建: 1--2, 1--3, 2--4, 3--4
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->neighbors = {n2, n3};
    n2->neighbors = {n4};
    n3->neighbors = {n4};
    Node* cloned = cloneGraph(n1);
    cout << cloned->val << endl;  // 预期: 1
    cout << cloned->neighbors.size() << endl;  // 预期: 2
    return 0;
}
