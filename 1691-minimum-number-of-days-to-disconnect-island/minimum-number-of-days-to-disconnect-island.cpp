class Solution {
public:
  int dx[4]={1,-1,0,0};
  int dy[4]={0,0,1,-1};
  int one=0;
  void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis){
    int n=grid.size(),m=grid[0].size();
    vis[i][j]=1;
    for(int k=0;k<4;++k){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]==1){
            dfs(x,y,grid,vis);
            one++;
        }
    }
  }
   int solve(vector<vector<int>>& grid){
      int n=grid.size(),m=grid[0].size();
        int ans;
        int cnt=0;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!vis[i][j]&& grid[i][j]==1){
                    one++;
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
   }
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int cnt=solve(grid);
        if(cnt>1 )return 0;
        if(one<=1)return one;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    one=0;
                    int cnt=solve(grid);
                    if(cnt>1)return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};