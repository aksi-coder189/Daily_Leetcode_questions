class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n= text.size();
        string s= "balloon";
        int ans = INT_MAX;
        map<char, int> frequencies;
        int a= s.size();
        for(int i=0; i<a; i++){
            for(int j=0; j<n; j++){
                if(text[j]==s[i]) frequencies[s[i]]++;
            }
            if(s[i]=='l'||s[i]=='o') frequencies[s[i]]/=2;
            ans = min(ans, frequencies[s[i]]);
        }
        return ans;
    }
};
