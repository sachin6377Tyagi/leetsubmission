class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int i,int j,int n,int m, vector<vector<bool>>&vis,vector<vector<char>>& grid){
    if(i>=0&&i<n&&j>=0&&j<m&&vis[i][j]==0&&grid[i][j]=='1'){
        vis[i][j]=1;
        for(int k=0;k<4;++k){
            int x=i+dx[k];
            int y=j+dy[k];
            dfs(x,y,n,m,vis,grid);
        }
    }
    else return;
}

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        int cnt=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,n,m,vis,grid);
                }
            }
        }
        return cnt;
    }
};