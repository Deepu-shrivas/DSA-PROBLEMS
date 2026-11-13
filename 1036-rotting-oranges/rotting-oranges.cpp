#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        int freshCount = 0;
        
        // 1. Initialize the queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        // If there are no fresh oranges initially, 0 minutes are needed
        if (freshCount == 0) return 0;
        
        int minutes = 0;
        // Direction vectors for 4-directional traversal (up, right, down, left)
        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, 1, 0, -1};
        
        // 2. Perform BFS level by level
        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            bool rottedAny = false;
            
            for (int k = 0; k < size; ++k) {
                auto [r, c] = q.front();
                q.pop();
                
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dRow[d];
                    int nc = c + dCol[d];
                    
                    // Check boundaries and if the cell contains a fresh orange
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // Rot the orange
                        q.push({nr, nc});
                        freshCount--;     // Decrease fresh count
                        rottedAny = true;
                    }
                }
            }
            
            if (rottedAny) {
                minutes++;
            }
        }
        
        // 3. Return result
        return freshCount == 0 ? minutes : -1;
    }
};
