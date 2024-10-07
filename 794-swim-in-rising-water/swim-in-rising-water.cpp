class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=grid[0][0];
        while(pq.size()){
            auto a=pq.top();
            pq.pop();
            int d=a[0],i=a[1],j=a[2];
            if(d>dist[i][j])continue;
            for(int k=0;k<4;++k){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 && x<n && y>=0 && y<m && dist[x][y]>max(d,grid[x][y])){
                    dist[x][y]=max(d,grid[x][y]);
                    pq.push({dist[x][y],x,y});
                }
            }
        }
        return dist[n-1][m-1];
    }
};