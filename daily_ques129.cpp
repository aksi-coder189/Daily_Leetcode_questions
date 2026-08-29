class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }
        sort(arr.begin(), arr.end());
        vector<int> indices(n);
        for(int i = 0; i < n; i++) {
            indices[i] = arr[i].second;
        }
        int l = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i].first - arr[i-1].first > limit) {
                sort(indices.begin() + l, indices.begin() + i);
                l = i;
            }
        }
        sort(indices.begin() + l, indices.end());
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[indices[i]] = arr[i].first;
        }
        return ans;
    }
};
