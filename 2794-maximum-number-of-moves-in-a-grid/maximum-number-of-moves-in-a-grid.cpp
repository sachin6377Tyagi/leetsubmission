class Solution {
public:
  int dx[3]={-1,0,1};
    int solve(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(j==m-1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        for(int k=0;k<3;++k){
            int x=i+dx[k];
            int y=j+1;
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]>grid[i][j])
            ans=max(ans,1+solve(x,y,n,m,grid,dp));
        }
        return dp[i][j]= ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
       int n=grid.size(),m=grid[0].size(); 
       int ans=0;
       vector<vector<int>>dp(n,vector<int>(m,-1));
       for(int i=0;i<n;++i){
        ans=max(ans,solve(i,0,n,m,grid,dp));
       }
       return ans;
    }
};