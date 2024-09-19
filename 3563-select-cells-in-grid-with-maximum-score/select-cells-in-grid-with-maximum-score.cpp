class Solution {
public:
   int solve(int i,int mask,vector<pair<int,int>>&vec,vector<vector<int>>&dp){
    int n=vec.size();
    if(i==n)return 0;
    if(dp[i][mask]!=-1)return dp[i][mask];
    int ans=solve(i+1,mask,vec,dp);

    int j=vec[i].second;
    //if((1<<j)&mask)ans=max(ans,solve(i+1,mask,vec,dp));
    if(!((1<<j)&mask)){
        int num=vec[i].first;
        int x=i;
        while(i<n && vec[i].first==num)i++;
        ans=max(ans,num+solve(i,mask|(1<<j),vec,dp));
        i=x;
    }
    return dp[i][mask]= ans;
   }
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
       vector<pair<int,int>>vec;
       for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)vec.push_back({grid[i][j],i});
       }
       sort(vec.rbegin(),vec.rend());
       int l=vec.size();
       vector<vector<int>>dp(l+1,vector<int>(1<<10,-1));
        return solve(0,0,vec,dp);
    }
};