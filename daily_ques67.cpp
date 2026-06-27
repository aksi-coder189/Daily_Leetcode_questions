class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, int> freq;
        for (int x : nums) freq[x]++;
        int ans = 1;
        if (freq.count(1)) {
            int c = freq[1];
            ans = max(ans, (c%2 == 1) ? c : c - 1);
        }
        for (auto &[start, c] : freq) {
            if (start == 1) continue;
            long long cur = start;
            int len = 0;
            while (freq.count(cur)) {
                if (freq[cur] >= 2) {
                    len += 2;
                    cur = cur * cur;
                }
                else {
                    len++;
                    break;
                }
            }
            if (len % 2 == 0) len--;
            ans = max(ans, len);
        }
        return ans;
    }
};
