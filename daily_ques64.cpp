class Solution {
public:
    static const long long MOD = 1000000007LL;
    vector<vector<long long>> multiply( const vector<vector<long long>>& A, const vector<vector<long long>>& B ) {
        int sz = A.size();
        vector<vector<long long>> C(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue;
                long long cur = A[i][k];
                for (int j = 0; j < sz; j++) {
                    if (B[k][j] == 0) continue;
                    C[i][j] = (C[i][j] + cur * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int s = 2 * m;
        vector<vector<long long>> T(s, vector<long long>(s, 0));
        for (int x = 0; x < m; x++) {
            for (int y = x + 1; y < m; y++) {
                T[x][m + y] = 1;
            }
            for (int y = 0; y < x; y++) {
                T[m + x][y] = 1;
            }
        }
        vector<vector<long long>> res(s, vector<long long>(s, 0));
        for (int i = 0; i < s; i++) {
            res[i][i] = 1;
        }
        long long pow = n - 1;
        while (pow > 0) {
            if (pow & 1) {
                res = multiply(res, T);
            }
            T = multiply(T, T);
            pow >>= 1;
        }
        long long ans = 0;
        for (int i = 0; i < s; i++) {
            long long rSum = 0;
            for (int j = 0; j < s; j++) {
                rSum = (rSum + res[i][j]) % MOD;
            }
            ans = (ans + rSum) % MOD;
        }
        return (int)ans;
    }
};
