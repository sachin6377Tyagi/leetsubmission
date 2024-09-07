class Solution {
public:
//    long long solve(int m,int n,map<pair<int,int>,long long>&mp,vector<vector<long long>>&dp){
//     if(dp[m][n]!=-1)return dp[m][n];
//      long long ans=mp[{m,n}];

//      for(int i=1;i<=(m/2);++i)ans=max(ans,solve(i,n,mp,dp)+solve(m-i,n,mp,dp));
//      for(int j=1;j<=(n/2);++j)ans=max(ans,solve(m,j,mp,dp)+solve(m,n-j,mp,dp));

//      return dp[m][n]= ans;
//    }
   long long solveTab(int m, int n, vector<vector<int>>& prices){
    vector<vector<long long>>dp(m+1,vector<long long>(n+1,0));
    for(int i=0;i<prices.size();++i)dp[prices[i][0]][prices[i][1]]=prices[i][2];
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            long long ans=dp[i][j];
            for(int k=1;k<=i-1;++k)ans=max(ans,dp[k][j]+dp[i-k][j]);
            for(int k=1;k<=j-1;++k)ans=max(ans,dp[i][k]+dp[i][j-k]);
            dp[i][j]=ans;
        }
    }
    return dp[m][n];
   }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        // map<pair<int,int>,long long>mp;
        // for(int i=0;i<prices.size();++i)mp[{prices[i][0],prices[i][1]}]=prices[i][2];
        // vector<vector<long long>>dp(m+1,vector<long long>(n+1,-1));
        // return solve(m,n,mp,dp);
        return solveTab(m,n,prices);
    }
};