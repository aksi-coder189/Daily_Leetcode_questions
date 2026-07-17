class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        long long int m = *max_element(nums.begin(), nums.end());
        vector<int> mp(m + 1, 0);
        vector<int> ans;
        for (auto n : nums) {
            mp[n]++;
        }
        vector<long long> cnt(m + 1, 0);
        for (int i = m; i >= 1; i--) {
            long long curr = 0;
            for (int k = i; k <= m; k += i) {
                curr += mp[k]; 
            }
            cnt[i] = curr * (curr - 1) / 2;
            for (int k = 2 * i; k <= m; k += i) {
                cnt[i] -= cnt[k]; 
            }
        }
        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (auto q : queries) {
            ans.push_back(lower_bound(cnt.begin(), cnt.end(), q + 1) - cnt.begin());
        }
        return ans;
    }
};
