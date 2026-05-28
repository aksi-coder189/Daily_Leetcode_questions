struct TrieNode {
    TrieNode* children[26];
    int bestWordIdx;

    TrieNode(int idx) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        bestWordIdx = idx;
    }
};

class Solution {
private:
    TrieNode* root;
    
    void insert(const string& word, int wordIdx, const vector<string>& wordsContainer) {
        TrieNode* curr = root;
        
        if (shouldUpdate(curr->bestWordIdx, wordIdx, wordsContainer)) {
            curr->bestWordIdx = wordIdx;
        }

        for (int i = word.length() - 1; i >= 0; --i) {
            int c = word[i] - 'a';
            if (!curr->children[c]) {
                curr->children[c] = new TrieNode(wordIdx);
            }
            curr = curr->children[c];
            
            if (shouldUpdate(curr->bestWordIdx, wordIdx, wordsContainer)) {
                curr->bestWordIdx = wordIdx;
            }
        }
    }

    bool shouldUpdate(int currIdx, int newIdx, const vector<string>& wordsContainer) {
        if (currIdx == -1) return true;
        if (wordsContainer[newIdx].length() < wordsContainer[currIdx].length()) return true;
        if (wordsContainer[newIdx].length() == wordsContainer[currIdx].length()) {
            return newIdx < currIdx;
        }
        return false;
    }

    int query(const string& word) {
        TrieNode* curr = root;
        int lastBest = root->bestWordIdx;

        for (int i = word.length() - 1; i >= 0; --i) {
            int c = word[i] - 'a';
            if (!curr->children[c]) {
                break;
            }
            curr = curr->children[c];
            lastBest = curr->bestWordIdx;
        }
        return lastBest;
    }

    void clear(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                clear(node->children[i]);
            }
        }
        delete node;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        root = new TrieNode(-1);

        for (int i = 0; i < wordsContainer.size(); ++i) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (const string& q : wordsQuery) {
            ans.push_back(query(q));
        }

        clear(root);
        
        return ans;
    }
};
