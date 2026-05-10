# 2770 : maximum-number-of-jumps-to-reach-the-last-index
# you are given a 0-indexed array nums of n integers and an integer target.

# You are initially positioned at index 0. In one step, you can jump from index i to any index j such that:

# 0 <= i < j < n
# -target <= nums[j] - nums[i] <= target
# Return the maximum number of jumps you can make to reach index n - 1.

# If there is no way to reach index n - 1, return -1.


class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // dp[i] stores the max jumps to reach index i
        vector<int> dp(n, -1);
        dp[0] = 0; // Starting point

        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                // Check if index i is reachable and jump is within target
                if (dp[i] != -1 && abs(nums[j] - nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};
