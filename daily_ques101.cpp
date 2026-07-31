class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        int ans = 0;
        for(char ch : word) freq[ch - 'a']++;
        sort(freq.begin(), freq.end());
        for(int i = 25, j = 0; i >= 0; i--) {
            int curr = 25 - i;
            if(curr % 8 == 0) j++;
            ans += freq[i] * j;
        }
        return ans;
    }
};
