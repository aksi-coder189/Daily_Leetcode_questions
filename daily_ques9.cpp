// 3742 : maximum-path-score-in-a-grid

// You are given an m x n grid where each cell contains one of the values 0, 1, or 2. You are also given an integer k.

// You start from the top-left corner (0, 0) and want to reach the bottom-right corner (m - 1, n - 1) by moving only right or down.

// Each cell contributes a specific score and incurs an associated cost, according to their cell values:

// 0: adds 0 to your score and costs 0.
// 1: adds 1 to your score and costs 1.
// 2: adds 2 to your score and costs 1. ​​​​​​​
// Return the maximum score achievable without exceeding a total cost of k, or -1 if no valid path exists.

// Note: If you reach the last cell but the total cost exceeds k, the path is invalid.

#include <iostream>
#include <vector>

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(m, vector<int>(k+1, -1)));

        int startVal = grid[0][0];
        int startCost = (startVal == 0 ? 0 : 1);

        if(startCost > k) return -1;

        dp[0][0][startCost] = startVal;

        int dir[2][2] = {{0,1},{1,0}};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int c=0;c<=k;c++){

                    if(dp[i][j][c] == -1) continue;

                    for(auto &d: dir){

                        int ni = i + d[0];
                        int nj = j + d[1];

                        if(ni<n && nj<m){

                            int val = grid[ni][nj];

                            int newCost = c + (val==0 ? 0 : 1);
                            int newScore = dp[i][j][c] + val;

                            if(newCost <= k){
                                dp[ni][nj][newCost] =
                                    max(dp[ni][nj][newCost], newScore);
                            }
                        }
                    }
                }
            }
        }

        int ans = -1;

        for(int c=0;c<=k;c++){
            ans = max(ans, dp[n-1][m-1][c]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // Example input
    vector<vector<int>> grid = {
        {0, 2, 3},
        {1, 0, 4},
        {2, 1, 0}
    };

    int k = 2;

    int result = obj.maxPathScore(grid, k);

    cout << "Max Path Score: " << result << endl;

    return 0;
}