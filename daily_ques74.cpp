class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        vector<bool> visited(n + 1, false);
        int ans = INT_MAX;
        queue<int> q;
        q.push(1);
        visited[1] = true;

        for (const auto& i : roads) {
            int a = i[0];
            int b = i[1];
            int dist = i[2];
            graph[a].push_back({b, dist});
            graph[b].push_back({a, dist});
        }
        
        while (!q.empty()) {
            int c = q.front();
            q.pop();

            for (const auto& edge : graph[c]) {
                int nc = edge.first;
                int dist = edge.second;
                ans = min(ans, dist);
                if (!visited[nc]) {
                    visited[nc] = true;
                    q.push(nc);
                }
            }
        }
        return ans;
    }
};
