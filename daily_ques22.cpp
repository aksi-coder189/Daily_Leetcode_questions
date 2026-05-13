class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> diff(2*limit+2,0);
        int n = nums.size();

        for (int i=0;i<n/2;i++){
            int a = nums[i];
            int b = nums[n-1-i];

            diff[2]+=2;
            diff[2*limit+1]-=2;

            int left = min(a,b)+1;
            int right = max(a,b)+limit;
            diff[left] -= 1;
            diff[right + 1] += 1;

            diff[a + b] -= 1;
            diff[a + b + 1] += 1;

        }
        int minmove = n;
        int currmove = 0;
        for (int i =2; i<=2*limit; i++){
            currmove += diff[i];
            minmove = min(minmove, currmove);
        }
        return minmove;
    }
};
