class Solution {
public:
    int minElement(vector<int>& nums) {
        int minval = INT_MAX;

        for ( int num : nums){
            int sum = 0;
    
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            minval = min(minval, sum);
        }
        
        return minval;
        
    }
};
