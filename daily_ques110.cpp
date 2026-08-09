class Solution {
    int memo[101][101];
    int suffixSum[101];

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(memo, 0, sizeof(memo));
        
        
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        return solve(0, 1, n);
    }

    int solve(int i, int M, int n) {
        if (i >= n) return 0;
        
        if (i + 2 * M >= n) return suffixSum[i];
        if (memo[i][M] != 0) return memo[i][M];

        int minoppstone = INT_MAX;

        for (int X = 1; X <= 2 * M; ++X) {

            minoppstone = min(minoppstone, solve(i + X, max(M, X), n));
        }
        return memo[i][M] = suffixSum[i] - minoppstone;
    }
};
