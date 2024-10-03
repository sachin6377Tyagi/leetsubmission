class Solution {
public:
  int dx[2]={1,0};
  int dy[2]={0,1};
   bool solve(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis){
    int n=grid.size(),m=grid[0].size();
    if(i==n-1 && j==m-1)return true;
    vis[i][j]=1;
    bool ans=0;
    for(int k=0;k<2;++k){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && !vis[x][y]){
            bool f=solve(x,y,grid,vis);
            ans=(ans|f);
            if(f)return true;
        }
    }
    return ans;
   }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        //if(n==1 && m==1)return !(grid[0][0]);
        //if(grid[0][0]==0 || grid[n-1][m-1]==0)return true;
        //if(grid[n-1][m-2]==0 && grid[n-2][m-1]==0)return true;
        cout<<n<<" "<<m<<endl;
        //if((n==1 && m==2)|| (n==2 && m==1))return false;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
            bool f=solve(0,0,grid,vis);
            if(!f)return true;
            f=solve(0,0,grid,vis);
            if(!f)return true;
        return false;
    }
};