class Solution {
public:
    vector<int> depth;
    vector<int> vis;
    void dfs(vector<vector<int>>& adj, int node, int parent) {
        for (auto nbr : adj[node]) {
            if (nbr != parent) {
                depth[nbr] = depth[node] + 1;
                dfs(adj, nbr, node);
            }
        }
    }
    int MOD = 1e9+7;

    int solve(vector<vector<int>>&dp,int ind,int n,int p,int sum){
       if(ind==n) return p==1;
       if(ind>n) return 0;
       if(dp[ind][p]!=-1) return dp[ind][p];
       int a = solve(dp,ind+1,n,(sum+1)%2,sum+1);
       int b = solve(dp,ind+1,n,(sum+2)%2,sum+2);
       return dp[ind][p] = (a+b)%MOD;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        depth.resize(n, 0);
        vis.resize(n, 0);
        dfs(adj, 0, -1);
        int max_node;
        int prev=-1;
        for(int i=0;i<n;i++){
          if(depth[i]>prev){
            prev=depth[i];
            max_node = i;
          }
        }
        vector<vector<int>> dp(prev,vector<int>(2,-1));
        return solve(dp,0,prev,0,0);
    }
};
