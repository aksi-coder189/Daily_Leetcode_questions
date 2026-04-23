// 2615 : Sum of distances 
// You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.
// Return the array arr.


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n, 0);
        unordered_map<int, vector<int>> posMap;

        // 1. Group indices by their values
        for (int i = 0; i < n; ++i) {
            posMap[nums[i]].push_back(i);
        }

        // 2. Process each group of indices
        for (auto& entry : posMap) {
            vector<int>& indices = entry.second;
            long long m = indices.size();
            
            // Total sum of all indices in this group
            long long totalSum = 0;
            for (int idx : indices) totalSum += idx;

            long long leftSum = 0;
            for (int i = 0; i < m; ++i) {
                long long currentIdx = indices[i];
                long long rightSum = totalSum - leftSum - currentIdx;

                // Distance from left: (count * currentIdx) - leftSum
                long long leftDist = (long long)i * currentIdx - leftSum;
                
                // Distance from right: rightSum - (count * currentIdx)
                long long rightDist = rightSum - (long long)(m - 1 - i) * currentIdx;

                res[currentIdx] = leftDist + rightDist;

                // Update leftSum for the next element in the group
                leftSum += currentIdx;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 1, 1, 2};
    
    vector<long long> result = sol.distance(nums);

    cout << "Sum of Distances: ";
    for (long long x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}