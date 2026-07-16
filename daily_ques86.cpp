class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans = 0;
        int m = 0;
        int i = 0;
        int j = nums.size() - 1;
        for (auto& n : nums) {
            m = ::max(m, n);
            n = gcd(n, m);
        }
        sort(nums.begin(), nums.end());
        while (i < j) {
            ans += gcd(nums[i], nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};
