// 3464 maximize the distance between points on a square

//You are given an integer side, representing the edge length of a square with corners at (0, 0), (0, side), (side, 0), and (side, side) on a Cartesian plane.

// You are also given a positive integer k and a 2D integer array points, where points[i] = [xi, yi] represents the coordinate of a point lying on the boundary of the square.

// You need to select k elements among points such that the minimum Manhattan distance between any two points is maximized.

// Return the maximum possible minimum Manhattan distance between the selected k points.

// The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef long long ll;
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n =  points.size();
        vector<long long > d;

        // converted 2d into 1d perimeter dist.
        for ( auto& p : points ){
            int x = p[0];
            int y = p[1];

            if ( y == 0 ) d.push_back(x);
            else if ( x == side ) d.push_back( side + y);
            else if ( y == side ) d.push_back( 2LL*side+(side-x));
            else d.push_back(3LL*side+(side-y));
        }
        sort(d.begin(), d.end());

        // circular array...
        for (int i=0; i<n; i++){
            d.push_back(d[i]+4LL*side);           
        }
        
        auto check = [&](long long mid){
            for (int i = 0; i < n; i++){
                long long last = i;
                bool ok = true;

                for (int j = 1; j < k; j++){
                    auto it = lower_bound(d.begin() + last + 1, d.begin() + i + n, d[last] + mid);

                    if (it == d.begin() + i + n){
                        ok = false;
                        break;
                    }

                    last = it - d.begin();
                }

                if (ok && (d[i] + 4LL * side - d[last] >= mid)) return true;
            }
            return false;
        };
        long long low = 1;
        long long high = 4LL*side ;
        int ans=0;
        while (low <=high ){
            long long mid = low + (high-low)/2;

            if (check(mid)){
                ans = mid; 
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }    
};


int main() {
    Solution sol;
    int side = 2;
    vector<vector<int>> points = {{0,0}, {1,2}, {2,0}, {2,2}};
    int k = 2;
    cout << "Maximized Minimum Distance: " << sol.maxDistance(side, points, k) << endl;
    return 0;
}