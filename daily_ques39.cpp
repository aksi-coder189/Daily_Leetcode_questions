class Solution {
public:
    vector<int> tree;
    vector<bool> ans;

    void update(int node, int l, int r, int idx, int val) {
        int mid = (l + r) / 2;
        if (l == r) {
            tree[node] = val;
            return;
        }
        if (idx <= mid) update(node * 2, l, mid, idx, val);
        else update(node * 2 + 1, mid + 1, r, idx, val);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MAX = 50000;
        tree.assign(4 * MAX + 4, 0);
        set<int> obs;
        obs.insert(0);
        obs.insert(MAX);

        for (auto &q : queries) {
            if (q[0] == 1)
                obs.insert(q[1]);
        }

        auto it = obs.begin();
        int prv = *it;
        ++it;

        while (it != obs.end()) {
            update(1, 0, MAX, *it, *it - prv);
            prv = *it;
            ++it;
        }

        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            auto &q = queries[i];
            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];
                int best = query(1, 0, MAX, 0, x);
                auto it = obs.upper_bound(x);
                int leftObs = *prev(it);
                best = max(best, x - leftObs);
                ans.push_back(best >= sz);
            } else {
                int x = q[1];
                auto it = obs.find(x);
                int L = *prev(it);
                int R = *next(it);
                obs.erase(it);
                update(1, 0, MAX, R, R - L);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
