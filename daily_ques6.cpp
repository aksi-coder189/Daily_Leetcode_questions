// 1559 : detect-cycles-in-2d-grid

// Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

// A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

// Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

// Return true if any cycle of the same value exists in grid, otherwise, return false.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rows, cols;
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

    bool dfs(int r, int c, int pr, int pc, char charTarget, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 1. Boundary aur character check
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == charTarget) {
                // 2. Agar visited hai aur parent nahi hai -> Cycle Found!
                if (visited[nr][nc]) {
                    if (nr != pr || nc != pc) return true;
                } else {
                    // 3. Recursive DFS
                    if (dfs(nr, nc, r, c, charTarget, grid, visited)) return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid[i][j], grid, visited)) return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Test Case: Cycle of 'a's exists
    vector<vector<char>> grid = {
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}
    };

    if (sol.containsCycle(grid)) {
        cout << "Cycle detected: Yes" << endl;
    } else {
        cout << "Cycle detected: No" << endl;
    }

    return 0;
}