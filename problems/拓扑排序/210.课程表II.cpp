#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto& p : prerequisites) {
        graph[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) 
        if (indegree[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int course = q.front(); q.pop();
        order.push_back(course);
        for (int neighbor : graph[course])
            if (--indegree[neighbor] == 0) q.push(neighbor);
    }
    return order.size() == numCourses ? order : vector<int>();
}

int main() {
    // 测试用例
    vector<vector<int>> p1 = {{1, 0}};
    auto r1 = findOrder(2, p1);
    for (int x : r1) cout << x << " ";
    cout << endl;  // 预期: 0 1
    
    vector<vector<int>> p2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    auto r2 = findOrder(4, p2);
    for (int x : r2) cout << x << " ";
    cout << endl;  // 预期: 0 1 2 3
    
    vector<vector<int>> p3 = {};
    auto r3 = findOrder(1, p3);
    for (int x : r3) cout << x << " ";
    cout << endl;  // 预期: 0
    return 0;
}
