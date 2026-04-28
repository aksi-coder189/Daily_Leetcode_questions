// 2033 : minimum operations to make a uni value grid

// You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

// A uni-value grid is a grid where all the elements of it are equal.

// Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nums.push_back(grid[i][j]);
            }
        }
        
        int rem = nums[0] % x;
        for (int val : nums) {
            if (val % x != rem) return -1;
        }

        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        
        int operations = 0;
        for (int val : nums) {
            operations += abs(val - median) / x;
        }
        
        return operations;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{2, 4}, {6, 8}};
    int x = 2;
    
    int result = sol.minOperations(grid, x);
    cout << "Minimum operations: " << result << endl; // Output: 4
    
    return 0;
}