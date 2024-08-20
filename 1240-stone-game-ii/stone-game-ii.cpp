class Solution {
public:
   int solve(int i,int m,int flag,int n,vector<int>&piles,vector<vector<vector<int>>>&dp){
    if(i==n)return 0;
    if(dp[i][m][flag]!=-1)return dp[i][m][flag];

    int ans=0;
    if(flag)ans=INT_MAX;
    int sum=0;
    for(int j=i;j<min(n,i+2*m);++j){
        sum+=piles[j];
        if(flag)ans=min(ans,solve(j+1,max(m,j-i+1),0,n,piles,dp));
        else ans=max(ans,sum+solve(j+1,max(m,j-i+1),1,n,piles,dp));
    }
    return dp[i][m][flag]= ans;
   } 
    int stoneGameII(vector<int>& piles) {
       int n=piles.size(); 
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2*n,vector<int>(2,-1)));
       return solve(0,1,0,n,piles,dp);
    }
};