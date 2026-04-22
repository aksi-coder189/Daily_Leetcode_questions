// 1722: Minimize Hamming Distance After Swap Operations

// You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.

//The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).

// Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);
        
        for (const auto& swap : allowedSwaps) {
            dsu.unite(swap[0], swap[1]);
        }
        
        // connecting each element
        unordered_map<int, unordered_map<int, int>> componentCounts;
        for (int i = 0; i < n; ++i) {
            int root = dsu.find(i);
            componentCounts[root][source[i]]++;
        }
        
        int matches = 0;
        for (int i = 0; i < n; ++i) {
            int root = dsu.find(i);
            if (componentCounts[root][target[i]] > 0) {
                matches++;
                componentCounts[root][target[i]]--;
            }
        }
        
        return n - matches;
    }
};

int main() {
    Solution sol;

    vector<int> source = {1, 2, 3, 4};
    vector<int> target = {2, 1, 4, 5};
    vector<vector<int>> allowedSwaps = {{0, 1}, {2, 3}};

    int result = sol.minimumHammingDistance(source, target, allowedSwaps);

    cout << "Minimum Hamming Distance: " << result << endl;

    return 0;
}