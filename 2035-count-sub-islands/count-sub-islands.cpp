class Solution {
public:
   int dx[4]={1,-1,0,0};
   int dy[4]={0,0,1,-1};
//    void dfs1(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&island){
//     int n=grid.size(),m=grid[0].size();
//     island[i][j]=1;
//     for(int k=0;k<4;++k){
//         int x=i+dx[k];
//         int y=j+dy[k];
//         if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && !island[x][y]){
//             dfs1(x,y,grid,island);
//         }
//     }
//    }

   bool dfs2(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<bool>>&vis,vector<vector<bool>>&island){
    bool flag=1;
     int n=grid1.size(),m=grid1[0].size();
    vis[i][j]=1;
    for(int k=0;k<4;++k){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0 && x<n && y>=0 && y<m && grid2[x][y]==1 && !vis[x][y]){
            bool f=dfs2(x,y,grid1,grid2,vis,island);
            flag=(f&flag);
        }
    }
    if((grid2[i][j]==1 && grid1[i][j]==0))flag=0;
    return flag;
   }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();
       vector<vector<bool>>island(n,vector<bool>(m,0)); 
    //    for(int i=0;i<n;++i){
    //     for(int j=0;j<m;++j){
    //         if(!island[i][j])dfs1(i,j,grid1,island);
    //     }
    //    }
       int ans=0;
       vector<vector<bool>>vis(n,vector<bool>(m,0)); 
        for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!vis[i][j] && grid2[i][j]==1){cout<<i<<" "<<j<<endl;
                bool flag=dfs2(i,j,grid1,grid2,vis,island);
                if(flag)ans++;
            }
        }
       }
       return ans;
    }
};