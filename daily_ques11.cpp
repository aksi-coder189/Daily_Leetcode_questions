// 788 - rotated digits 

// An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

// A number is valid if each digit remains a digit after rotation. For example:

// 0, 1, and 8 rotate to themselves,
// 2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
// 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.
// Given an integer n, return the number of good integers in the range [1, n].

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        
        for (int i = 1; i <= n; i++) {
            if (isGood(i)) {
                count++;
            }
        }
        
        return count;
    }

private:
    bool isGood(int num) {
        bool hasGameChanger = false;
        string s = to_string(num);
        
        for (char c : s) {
            if (c == '3' || c == '4' || c == '7') {
                return false; // Invalid digit found
            }
            if (c == '2' || c == '5' || c == '6' || c == '9') {
                hasGameChanger = true; // Change no on rotation
            }
        }
        
        return hasGameChanger;
    }
};

int main() {
    Solution sol;
    int n = 10;
    
    cout << "Total Good Numbers up to " << n << ": " << sol.rotatedDigits(n) << endl;
    
    return 0;
}