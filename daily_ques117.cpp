class Solution {
int memo[501][501];
    int prefixSum[501];

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) memo[i][j] = 0;
        }
        
        prefixSum[0] = 0;
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }
        
        return solve(0, n - 1, stoneValue);
    }

    int solve(int i, int j, vector<int>& stoneValue) {
        if (i == j) return 0;
        if (memo[i][j] != 0) return memo[i][j];

        int res = 0;
        
        for (int p = i; p < j; p++) {
            int leftSum = prefixSum[p + 1] - prefixSum[i];
            int rightSum = prefixSum[j + 1] - prefixSum[p + 1];

            if (leftSum < rightSum) {
                
                res = max(res, leftSum + solve(i, p, stoneValue));
            } else if (rightSum < leftSum) {
                
                res = max(res, rightSum + solve(p + 1, j, stoneValue));
            } else {
                
                res = max(res, leftSum + max(solve(i, p, stoneValue), solve(p + 1, j, stoneValue)));
            }
        }
        return memo[i][j] = res;
    }
};
