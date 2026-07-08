class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;

        vector<int> digits;
        vector<int> orig_idx;
        for (int i = 0; i < m; ++i) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                orig_idx.push_back(i);
            }
        }

        int n = digits.size();

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<long long> prefix_sum(n + 1, 0);
        vector<long long> P(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + digits[i];
            P[i + 1] = (P[i] * 10 + digits[i]) % MOD;
        }

        vector<int> first_nz(m + 1, n);
        int current_nz = n;
        for (int i = m - 1; i >= 0; --i) {
            if (s[i] != '0') {
                current_nz--;
            }
            first_nz[i] = current_nz;
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int L = first_nz[l];
            int R = first_nz[r + 1] - 1; 

            if (L > R) {
                answer.push_back(0);
                continue;
            }

            int idx_L = L + 1;
            int idx_R = R + 1;

            long long digit_sum = prefix_sum[idx_R] - prefix_sum[idx_L - 1];

            long long len = idx_R - idx_L + 1;
            long long x = (P[idx_R] - (P[idx_L - 1] * pow10[len]) % MOD + MOD) % MOD;

            long long ans = (x * digit_sum) % MOD;
            answer.push_back(ans);
        }

        return answer;
    }
};
