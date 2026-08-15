class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xor_all = 0;
        bool has_non_zero = false;

        for (int x : nums) {
            xor_all ^= x;
            if (x != 0) {
                has_non_zero = true;
            }
        }

        if (xor_all != 0) {
            return n;
        }

        return has_non_zero ? n - 1 : 0;
    }
};
