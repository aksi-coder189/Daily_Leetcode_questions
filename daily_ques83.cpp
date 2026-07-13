class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string digits = "123456789";
        
        for (int length = 2; length <= 9; ++length) {
            for (int start = 0; start <= 9 - length; ++start) {
                string sub = digits.substr(start, length);
                int num = stoi(sub);
                
                
                if (num >= low && num <= high) {
                    res.push_back(num);
                }
            }
        }
        
        return res;
    }
};
