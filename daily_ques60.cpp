class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        long long ans=0;
        restrictions.push_back({1,0});
        int s = restrictions.size();
        sort(restrictions.begin(),restrictions.end());
        if(restrictions[s-1][0]!=n){
            restrictions.push_back({n,n}); 
            s++;
        }
        for(int i=1;i<s;i++){
            restrictions[i][1]= min(restrictions[i][1],restrictions[i][0]-restrictions[i-1][0]+restrictions[i-1][1]);
        }
        for(int i=s-2;i>=1;i--){
            restrictions[i][1]= min(restrictions[i][1],restrictions[i+1][0]-restrictions[i][0]+restrictions[i+1][1]);
        }
        for(int i=0;i<s-1;i++){
            long long m=(restrictions[i][1]+restrictions[i+1][1]+(restrictions[i+1][0]-restrictions[i][0]))/2;
            ans=max(ans,m);
        }
        return (int)ans;
    }
};
