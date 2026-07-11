class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        int ans = 0;
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; i++) {
            int nodes = 0;
            int edgeCnt = 0; 
            if (vis[i]) continue;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                nodes++;
                edgeCnt += adj[u].size();
                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            edgeCnt /= 2;
            if (edgeCnt == (nodes*(nodes-1)/2)) ans++;
        }
        return ans;
    }
};
