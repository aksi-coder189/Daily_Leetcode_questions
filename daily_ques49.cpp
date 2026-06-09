class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = *max_element(nums.begin(), nums.end());
        int m = *min_element(nums.begin(), nums.end());
        return 1LL * (n - m) * k; 
    }
};
