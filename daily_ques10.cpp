// 396 - rotate function 

// You are given an integer array nums of length n.

// Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

// F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
// Return the maximum value of F(0), F(1), ..., F(n-1).

// The test cases are generated so that the answer fits in a 32-bit integer.

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0;
        long long f = 0;

        for (int i = 0; i<n; i++){
            sum+=nums[i];
            f+=(long long)i*nums[i];

        }
        long long maxval = f;

        for (int i = n-1; i>=0; i--){
            f = f+sum-n*nums[i];
            maxval = max(maxval, f);
        }
        return (int)maxval;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 3, 2, 6};
    
    int result = sol.maxRotateFunction(nums);
    cout << "Maximum value of Rotate Function: " << result << endl;
    
    return 0;
}