class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n= arr.size();
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        for (int i = 0; i < n; i++) {
            arr[i] = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin()+1;
        }
        return arr;
    }
};
