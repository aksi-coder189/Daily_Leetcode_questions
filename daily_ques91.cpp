class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> z;
        int run = 0;
        int ans = 0;
        for (char c : s)
            if(c == '0') ++run;
            else if(run) z.push_back(exchange(run, 0));
        if (run) z.push_back(run);
        for (int i = 1; i < z.size(); ++i)
            ans = max(ans, z[i - 1] + z[i]);

        return ranges::count(s, '1') + ans;
    }
};
