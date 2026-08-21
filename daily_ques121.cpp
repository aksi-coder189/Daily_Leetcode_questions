class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto countAmounts = [&](long long x) {
            long long count = 0;
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long lcm_val = 1;
                int subset_size = 0;
                bool overflow = false;

                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        subset_size++;
                        long long g = std::gcd(lcm_val, (long long)coins[i]);
                        lcm_val = (lcm_val / g) * coins[i];
                        if (lcm_val > x) {
                            overflow = true;
                            break;
                        }
                    }
                }

                if (overflow) continue;

                if (subset_size % 2 == 1) {
                    count += x / lcm_val;
                } else {
                    count -= x / lcm_val;
                }
            }
            return count;
        };

        long long low = 1;
        long long high = 1LL * *min_element(coins.begin(), coins.end()) * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countAmounts(mid) >= k) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
