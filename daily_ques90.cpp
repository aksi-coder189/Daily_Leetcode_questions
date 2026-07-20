class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m= grid.size();
        int n= grid[0].size();
        int t= m*n;
        k = k % t;
        if (!k) return grid;
        auto shift = [&](int i, int j) {
            while (i < j) {
                swap(grid[i / n][i % n], grid[j / n][j % n]);
                i++;
                j--;
            }
        };
        shift(0, t - 1);
        shift(0, k - 1);
        shift(k, t - 1);
        return grid;
    }
};
