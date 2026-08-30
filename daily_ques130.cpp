class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n= nums.size();
        int l= 0;
        int r= 0;
        int ans= n;
        for (int i=1; i<n; i++) {
            if (nums[i]< nums[l]) l= i; 
            if (nums[i]> nums[r]) r= i;
        }
        if (l<r) swap(l, r);
        for (int i=0; i<=n; i++) {
            int extra= 0;
            if (r>= i) extra= n-r;
            else if (l>=i) extra = n-l;
            ans = min(ans, i+extra);
        }
        return ans;
    }
};
