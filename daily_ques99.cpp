class Solution {
public:
    long long comb(int n, int r, int lim) {
        r = min(r, n - r);
        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n-r+i)/i;
            if (ans > lim) return lim + 1;
        }
        return ans;
    }

    long long calc(vector<int> &cnt, int rem, int lim) {
        long long ans = 1;
        for (int x : cnt) {
            if (!x) continue;
            ans *= comb(rem, x, lim);
            if (ans > lim) return lim + 1;
            rem -= x;
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;
        int n = s.size(), m = n / 2;
        string ans(n, ' ');

        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) ans[m] = 'a' + i;
            cnt[i] /= 2;
        }
        if (calc(cnt, m, k) < k) return "";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 26; j++) {
                if (!cnt[j]) continue;
                cnt[j]--;
                long long cur = calc(cnt, m - i - 1, k);
                if (cur >= k) {
                    ans[i] = 'a' + j;
                    break;
                }
                k -= cur;
                cnt[j]++;
            }
        }
        for (int i = 0; i < m; i++) ans[n - 1 - i] = ans[i];
        return ans;
    }
};
