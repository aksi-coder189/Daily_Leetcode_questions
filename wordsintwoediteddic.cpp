// You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.

// In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.

// Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.



#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;

        for (const string& q : queries) {
            bool found = false;
            for (const string& d : dictionary) {
                // Same length check (requirement of the problem)
                if (q.length() == d.length()) {
                    int edits = 0;
                    for (int i = 0; i < q.length(); ++i) {
                        if (q[i] != d[i]) {
                            edits++;
                        }
                        // Optimization: if edits > 2, this dictionary word fails
                        if (edits > 2) break; 
                    }

                    if (edits <= 2) {
                        found = true;
                        break; // Found a match, no need to check other dictionary words
                    }
                }
            }
            if (found) {
                result.push_back(q);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case
    vector<string> queries = {"word", "note", "ants", "wood"};
    vector<string> dictionary = {"wood", "joke", "moat"};

    vector<string> result = sol.twoEditWords(queries, dictionary);

    cout << "Words within 2 edits: ";
    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}