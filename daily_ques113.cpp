struct Node {
    int max_len;
    int prefix_len;
    int suffix_len;
    char first_char;
    char last_char;

    Node() : max_len(0), prefix_len(0), suffix_len(0), first_char(0), last_char(0) {}
};

class Solution {
private:
    vector<Node> tree;
    int n;

    Node merge(const Node& left, const Node& right, int left_size, int right_size) {
        Node parent;
        parent.first_char = left.first_char;
        parent.last_char = right.last_char;
        
        parent.max_len = max(left.max_len, right.max_len);
        parent.prefix_len = left.prefix_len;
        parent.suffix_len = right.suffix_len;

        // Check if characters at the boundary merge
        if (left.last_char == right.first_char) {
            parent.max_len = max(parent.max_len, left.suffix_len + right.prefix_len);
            
            if (left.prefix_len == left_size) {
                parent.prefix_len = left_size + right.prefix_len;
            }
            if (right.suffix_len == right_size) {
                parent.suffix_len = right_size + left.suffix_len;
            }
        }

        return parent;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node].max_len = 1;
            tree[node].prefix_len = 1;
            tree[node].suffix_len = 1;
            tree[node].first_char = s[start];
            tree[node].last_char = s[start];
            return;
        }
        int mid = start + (end - start) / 2;
        int left_child = 2 * node;
        int right_child = 2 * node + 1;

        build(s, left_child, start, mid);
        build(s, right_child, mid + 1, end);

        tree[node] = merge(tree[left_child], tree[right_child], mid - start + 1, end - mid);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node].first_char = ch;
            tree[node].last_char = ch;
            return;
        }
        int mid = start + (end - start) / 2;
        int left_child = 2 * node;
        int right_child = 2 * node + 1;

        if (idx <= mid) {
            update(left_child, start, mid, idx, ch);
        } else {
            update(right_child, mid + 1, end, idx, ch);
        }

        tree[node] = merge(tree[left_child], tree[right_child], mid - start + 1, end - mid);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.length();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);

        int k = queryIndices.size();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].max_len;
        }

        return ans;
    }
};
