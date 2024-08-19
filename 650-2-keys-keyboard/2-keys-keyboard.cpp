class Solution {
public:
   int solve(int i,int j,int n,vector<vector<int>>&dp,set<pair<int,int>>&st){
    if(i==n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(st.find({i,j})!=st.end())return 1e7;
    else st.insert({i,j});

    int ans=INT_MAX;
    if( i+j<=n)ans=min(ans,1+solve(i+j,j,n,dp,st));
    if(i<=n)ans=min(ans,1+solve(i,i,n,dp,st));

    return dp[i][j]= ans;
   }
    int minSteps(int n) {
        if(n==1)return 0;
        set<pair<int,int>>st;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return solve(1,0,n,dp,st); 
    }
};