// 3225 : maximum score from grid operations

// You are given a 2D matrix grid of size n x n. Initially, all cells of the grid are colored white. In one operation, you can select any cell of indices (i, j), and color black all the cells of the jth column starting from the top row down to the ith row.

// The grid score is the sum of all grid[i][j] such that cell (i, j) is white and it has a horizontally adjacent black cell.

// Return the maximum score that can be achieved after some number of operations.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        
        vector<vector<long long>> pre(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                pre[j][i + 1] = pre[j][i] + grid[i][j];
            }
        }
        
        const long long INF = -1e15;
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));
        for (int y = 0; y <= n; ++y) {
            dp[0][y] = 0;
        }
        
        for (int i = 1; i < n; ++i) {
            vector<vector<long long>> next_dp(n + 1, vector<long long>(n + 1, INF));
            
            vector<long long> max_dp_x(n + 1, INF);
            for (int x = 0; x <= n; ++x) {
                for (int w = 0; w <= n; ++w) {
                    max_dp_x[x] = max(max_dp_x[x], dp[w][x]);
                }
            }
            
            for (int x = 0; x <= n; ++x) {
                long long max_w_le_x = INF;
                for (int w = 0; w <= x; ++w) {
                    max_w_le_x = max(max_w_le_x, dp[w][x]);
                }
                
                vector<long long> suf(n + 2, INF);
                for(int w = n; w >= 0; --w) {
                    suf[w] = max(dp[w][x], suf[w + 1]);
                }
                
                long long max_w_mid = INF;
                
                for (int y = 0; y <= n; ++y) {
                    long long max_val = INF;
                    
                    if (x >= y) {
                        if (max_dp_x[x] != INF) {
                            max_val = max_dp_x[x] + pre[i][x] - pre[i][y];
                        }
                    } else {
                        if (dp[y][x] != INF) {
                            max_w_mid = max(max_w_mid, dp[y][x] - pre[i - 1][y]);
                        }
                        
                        if (max_w_le_x != INF) {
                            max_val = max(max_val, max_w_le_x + pre[i - 1][y] - pre[i - 1][x]);
                        }
                        if (max_w_mid != INF) {
                            max_val = max(max_val, max_w_mid + pre[i - 1][y]);
                        }
                        if (suf[y + 1] != INF) {
                            max_val = max(max_val, suf[y + 1]);
                        }
                    }
                    next_dp[x][y] = max_val;
                }
            }
            dp = move(next_dp);
        }
        
        long long ans = 0;
        for (int x = 0; x <= n; ++x) {
            for (int y = 0; y <= n; ++y) {
                ans = max(ans, dp[x][y]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0,0,0,0,0},{0,0,3,0,0},{0,1,0,0,0},{5,0,0,3,0},{0,0,0,0,2}};
    cout << "Maximum Grid Score: " << sol.maximumScore(grid) << endl;
    return 0;
}