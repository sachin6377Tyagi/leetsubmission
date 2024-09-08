class Solution {
public:
   int dx[8]={-2,-2,2,2,-1,-1,1,1};
   int dy[8]={-1,1,-1,1,-2,2,-2,2};
   int arr[16][50][50];
   bool vis[16][50][50]={0};
   void bfs(int ind,vector<vector<int>>& pos){
    queue<pair<int,int>>q;
    int i=pos[ind][0],j=pos[ind][1];
    q.push({i,j});
    vis[ind][i][j]=1;
    int d=0;
    while(q.size()){
        int l=q.size();
        while(l--){
            auto it=q.front();
        q.pop();
        int x1=it.first,y1=it.second;
        arr[ind][x1][y1]=d;
        for(int k=0;k<8;++k){
            int x=x1+dx[k];
            int y=y1+dy[k];
            if(x>=0 && x<50 && y>=0 && y<50 && !vis[ind][x][y]){
                q.push({x,y});
                vis[ind][x][y]=1;
                //for(auto it)
            }
        }
        }
        d++;
    }
   }

   int solve(int mask,int flag,int ind,int n, vector<vector<int>>& pos,vector<vector<vector<int>>>&dp){
    if(mask==(1<<n)-1)return 0;
    if(dp[mask][flag][ind]!=-1)return dp[mask][flag][ind];
    
     int ans=(flag==0?0:1e9);

     for(int i=0;i<n;++i){
        int x=pos[i][0],y=pos[i][1];
        if(!(mask&(1<<i))){
            if(flag==0)ans=max(ans,arr[ind][x][y]+solve(mask|(1<<i),1,i,n,pos,dp));
            else ans=min(ans,arr[ind][x][y]+solve(mask|(1<<i),0,i,n,pos,dp));
        }
     }
     return dp[mask][flag][ind]= ans;
   }
//    int solveTab(int n, vector<vector<int>>& pos){
//     vector<vector<vector<int>>>dp((1<<n),vector<vector<int>>(2,vector<int>(n+1,0)));
//     for(int mask=(1<<n)-1;mask>=0;mask--){
//         for(int ind=n;ind>=0;ind--){
//             for(int flag=0;flag<2;++flag){
//                 int ans=(flag==0?0:1e9);
//                 for(int i=0;i<n;++i){
//                     int x=pos[i][0],y=pos[i][1];
//                     if(!(mask&(1<<i))){
//                         if(flag==0)ans=max(ans,arr[ind][x][y]+dp[mask|(1<<i)][1][i]);
//                         else ans=min(ans,arr[ind][x][y]+dp[mask|(1<<i)][0][i]);
//                     }
//                 }
//                 dp[mask][flag][ind]=ans;
//             }
//         }
//     }
//     return dp[0][0][0];
//    }
    int maxMoves(int kx, int ky, vector<vector<int>>& pos) {
        int n=pos.size();
        
        pos.push_back({kx,ky});
        for(int i=0;i<=n;++i){
            bfs(i,pos);
        }
        vector<vector<vector<int>>>dp((1<<n),vector<vector<int>>(2,vector<int>(n+1,-1)));
       return solve(0,0,n,n,pos,dp);
       //return solveTab(n,pos);
    }
};