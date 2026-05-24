class Solution {
int memo[1001];

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int max_visited = 0;
        fill(memo, memo + n, 0);

        for (int i = 0; i < n; i++) {
            max_visited = max(max_visited, solve(i, arr, d));
        }
        
        return max_visited;
    }

    int solve(int i, vector<int>& arr, int d) {
        if (memo[i] != 0) return memo[i];

        int n = arr.size();
        int res = 1;

        for (int j = i + 1; j <= min(i + d, n - 1); j++) {
            if (arr[i] > arr[j]) {
                res = max(res, 1 + solve(j, arr, d));
            } else {
                break; 
            }
        }

        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (arr[i] > arr[j]) {
                res = max(res, 1 + solve(j, arr, d));
            } else {
                break; 
            }
        }

        return memo[i] = res;
    }
};
