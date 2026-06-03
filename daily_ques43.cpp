class Solution {
public:
    long long solve(vector<int>& Astart, vector<int>& Adur, vector<int>& Bstart, vector<int>& Bdur) {
        int m = Bstart.size();
        vector<pair<long long,long long>> rides;        
        vector<long long> starts(m);
        vector<long long> prefMinDur(m);
        vector<long long> suffMinFinish(m);
        long long ans = LLONG_MAX;

        for (int i = 0; i < m; i++) {
            rides.push_back({Bstart[i], Bdur[i]});
        }

        sort(rides.begin(), rides.end());

        for (int i = 0; i < m; i++) {
            starts[i] = rides[i].first;
        }

        prefMinDur[0] = rides[0].second;
        for (int i = 1; i < m; i++) {
            prefMinDur[i] = min(prefMinDur[i - 1], rides[i].second);
        }

        suffMinFinish[m - 1] = rides[m - 1].first + rides[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            suffMinFinish[i] = min(suffMinFinish[i + 1], rides[i].first + rides[i].second);
        }

        for (int i = 0; i < (int)Astart.size(); i++) {
            long long finishA = (long long)Astart[i] + Adur[i];
            int k = upper_bound(starts.begin(), starts.end(), finishA) - starts.begin();
            if (k > 0) {
                ans = min(ans, finishA + prefMinDur[k - 1]);
            }
            if (k < m) {
                ans = min(ans, suffMinFinish[k]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        long long ans = LLONG_MAX;
        ans = min(ans,solve(landStartTime, landDuration, waterStartTime, waterDuration));
        ans = min(ans, solve(waterStartTime, waterDuration, landStartTime, landDuration));
        return (int)ans;
    }
};
