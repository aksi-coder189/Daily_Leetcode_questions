class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m= grid.size();
        int n= grid[0].size();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> q;
        dist[0][0] = grid[0][0];
        q.push_front({0, 0});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();
            if (x == m - 1 && y == n - 1) return dist[x][y] < health;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int a = grid[nx][ny];
                if (dist[x][y] + a < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + a;
                    if (a == 0) q.push_front({nx, ny});
                    else q.push_back({nx, ny});
                }
            }
        }
        return dist[m - 1][n - 1] < health;
    }
};
