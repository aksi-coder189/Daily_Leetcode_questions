class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> last(m + 1, -1);
        last[m] = n;

        int idx = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (idx >= 0 && word1[idx] != word2[j]) {
                idx--;
            }
            last[j] = idx;
            if (idx >= 0) {
                idx--; 
            }
        }

        vector<int> ans;
        bool changed = false;
        int j = 0;

        for (int i = 0; i < n && j < m; ++i) {
            bool isMatch = (word1[i] == word2[j]);
            
            bool canMismatch = !changed && (last[j + 1] > i);

            if (isMatch || canMismatch) {
                if (!isMatch) {
                    changed = true;
                }
                ans.push_back(i);
                j++;
            }
        }

        return ans.size() == m ? ans : vector<int>();
    }
};
