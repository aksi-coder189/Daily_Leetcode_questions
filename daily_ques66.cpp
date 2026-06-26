class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(); 
        int pref = n;
        vector<int> freq(2*n+1);
        freq[n] = 1;
        long long a = 0, ans = 0;
        for (int i : nums) {
            if (i == target) a += freq[pref++];
            else a -= freq[--pref];
            ++freq[pref];
            ans += a;
        }
        return ans;
    }
};
