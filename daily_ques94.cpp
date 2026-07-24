class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        const int max_xor = 2048;
        vector<bool> p(max_xor, false);
        vector<bool> t(max_xor, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                p[nums[i] ^ nums[j]] = true;
            }
        }

        for (int x = 0; x < max_xor; x++) {
            if (!p[x]) continue;
            for (int v : nums) {
                t[x ^ v] = true;
            }
        }
        for(int i = 0; i < max_xor; i++){
            if(t[i]) ans++;
        }
        return ans;
    }
};
