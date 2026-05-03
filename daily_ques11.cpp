// 796 rotate string 

// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        string doubled = s + s;
        if (doubled.find(goal) != string::npos) {
            return true;
        }

        return false;
    }
};

int main() {
    Solution sol;
    
    string s = "abcde";
    string goal = "cdeab";

    if (sol.rotateString(s, goal)) {
        cout << "Result: True (String can be rotated)" << endl;
    } else {
        cout << "Result: False" << endl;
    }

    return 0;
}