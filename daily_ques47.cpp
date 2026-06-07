/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> mp1;
        for(int i=0;i<n;i++){
            if(!mp.count(descriptions[i][1])){
                mp[descriptions[i][1]] = new TreeNode(descriptions[i][1]);
            }
            if(!mp.count(descriptions[i][0])){
                mp[descriptions[i][0]] = new TreeNode(descriptions[i][0]);
            }
            if(descriptions[i][2] == 1){
                mp[descriptions[i][0]]->left = mp[descriptions[i][1]];
            }
            else{
                mp[descriptions[i][0]]->right = mp[descriptions[i][1]];
            }
            mp1.insert(descriptions[i][1]);
        }
        for(int i=0;i<n;i++){
            if(!mp1.count(descriptions[i][0])){
                return mp[descriptions[i][0]];
            }
        }
        return nullptr;
    }
};
