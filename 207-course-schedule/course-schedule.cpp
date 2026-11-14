#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build adjacency list and compute in-degrees
        // [a, b] means b -> a
        for (const auto& pair : prerequisites) {
            int course = pair[0];
            int pre = pair[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }

        // Push all courses with 0 prerequisites into the queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int completed = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            completed++;

            for (int neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return completed == numCourses;
    }
};
