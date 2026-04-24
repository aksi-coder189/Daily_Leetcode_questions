// 2833 : Furthest Point From Origin

// You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.

// In the ith move, you can choose one of the following directions:

// move to the left if moves[i] = 'L' or moves[i] = '_'
// move to the right if moves[i] = 'R' or moves[i] = '_'
// Return the distance from the origin of the furthest point you can get to after n moves.


#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countl=0;
        int countr=0;
        int countus=0;

        for (char c : moves ){
            if ( c == 'L') countl++;
            else if ( c == 'R') countr++;
            else countus++;
        }
        return abs(countl - countr) + countus;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string moves1 = "L_RL__R";
    cout << "Test 1 Distance: " << sol.furthestDistanceFromOrigin(moves1) << endl; 

    // Test Case 2
    string moves2 = "_R__LL_";
    cout << "Test 2 Distance: " << sol.furthestDistanceFromOrigin(moves2) << endl;
    

    return 0;
}