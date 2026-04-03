#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto& p : prerequisites) {
        graph[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) 
        if (indegree[i] == 0) q.push(i);
    int count = 0;
    while (!q.empty()) {
        int course = q.front(); q.pop();
        count++;
        for (int neighbor : graph[course])
            if (--indegree[neighbor] == 0) q.push(neighbor);
    }
    return count == numCourses;
}

int main() {
    // 测试用例
    vector<vector<int>> p1 = {{1, 0}};
    cout << canFinish(2, p1) << endl;                      // 预期: 1 (True)
    vector<vector<int>> p2 = {{1, 0}, {0, 1}};
    cout << canFinish(2, p2) << endl;                      // 预期: 0 (False)
    vector<vector<int>> p3 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    cout << canFinish(4, p3) << endl;                      // 预期: 1 (True)
    return 0;
}
