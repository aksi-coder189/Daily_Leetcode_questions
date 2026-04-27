// 1391 : check if there is a valid path in a grid

// You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:

// 1 which means a street connecting the left cell and the right cell.
// 2 which means a street connecting the upper cell and the lower cell.
// 3 which means a street connecting the left cell and the lower cell.
// 4 which means a street connecting the right cell and the lower cell.
// 5 which means a street connecting the left cell and the upper cell.
// 6 which means a street connecting the right cell and the upper cell.

// You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

// Notice that you are not allowed to change any street.

// Return true if there is a valid path in the grid or false otherwise.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Directions: 0: Up, 1: Down, 2: Left, 3: Right
        // pipe_dirs[type] = {available directions}
        vector<vector<int>> pipe_dirs = {
            {}, // index 0 not used
            {2, 3}, // 1: Left, Right
            {0, 1}, // 2: Up, Down
            {2, 1}, // 3: Left, Down
            {3, 1}, // 4: Right, Down
            {2, 0}, // 5: Left, Up
            {3, 0}  // 6: Right, Up
        };

        // Offset for r and c based on directions (Up, Down, Left, Right)
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        // To enter from direction d, the neighbor must have the opposite exit
        // Opposite of Up(0) is Down(1), Left(2) is Right(3)
        int opp[] = {1, 0, 3, 2};

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            int r = p.first;
            int c = p.second;

            if (r == m - 1 && c == n - 1) return true;

            int type = grid[r][c];
            for (int dir : pipe_dirs[type]) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int nextType = grid[nr][nc];
                    bool canEnter = false;
                    // Check if next pipe has an opening facing the current pipe
                    for (int nextDir : pipe_dirs[nextType]) {
                        if (nextDir == opp[dir]) {
                            canEnter = true;
                            break;
                        }
                    }

                    if (canEnter) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{2, 4, 3}, {6, 5, 2}};
    
    if (sol.hasValidPath(grid)) {
        cout << "Path exists!" << endl;
    } else {
        cout << "No valid path." << endl;
    }
    
    return 0;
}