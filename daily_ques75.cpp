class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        vector<vector<int>> nc(n, vector<int>(n,-1));
        vector<vector<int>> np(n, vector<int>(n,0));
        nc[n-1][n-1] = 0;   
        np[n-1][n-1] = 1;   

        for (int i=n-1; i>=0; --i) {
            for (int j=n-1; j>=0; --j) {
                int best = -1;
                long long cnt = 0;
                if (i== n-1 && j== n-1) continue;  
                if (board[i][j] == 'X') continue;  
                if (j+1 < n) best = max(best, nc[i][j+1]);
                if (i+1 < n) best = max(best, nc[i+1][j]);          
                if (i+1 < n && j+1 < n) best = max(best, nc[i+1][j+1]);  
                if (best == -1) continue; 
                if (j+1 < n && nc[i][j+1] == best) cnt += np[i][j+1];     
                if (i+1 < n && nc[i+1][j] == best) cnt += np[i+1][j];
                if (i+1 < n && j+1 < n && nc[i+1][j+1] == best) cnt += np[i+1][j+1];
                cnt %= MOD;
                int val = (board[i][j] == 'E') ? 0 : board[i][j] - '0';
                nc[i][j] = best + val;
                np[i][j] = (int)cnt;
            }
        }
        if (nc[0][0] == -1) return {0,0};
        return {nc[0][0], np[0][0]};
    }
};
