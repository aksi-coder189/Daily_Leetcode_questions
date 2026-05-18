class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> indicesOfValue;
        for (int i = 0; i < n; i++) {
            indicesOfValue[arr[i]].push_back(i);
        }

        vector<int> visited(n, false);
        queue<int> q;
        
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front();
                q.pop();

                if (i == n - 1) return steps;
                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }
                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }
                if (indicesOfValue.count(arr[i])) {
                    for (int nextIndex : indicesOfValue[arr[i]]) {
                        if (!visited[nextIndex]) {
                            visited[nextIndex] = true;
                            q.push(nextIndex);
                        }
                    }
                    indicesOfValue.erase(arr[i]);
                }
            }
            steps++;
        }

        return -1;
    }
};
