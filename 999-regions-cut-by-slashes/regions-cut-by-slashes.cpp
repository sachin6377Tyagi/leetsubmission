class Solution {
public:
int ans=0;
   int findPar(int u,vector<int>&par){
    if(par[u]==u)return u;
    return findPar(par[u],par);
   }

  void unionSet(int u,int v,vector<int>&par,vector<int>&rank){
    u=findPar(u,par);
    v=findPar(v,par);
    if(u==v){
        ans++;
        return;
    }
    if(rank[u]<=rank[v]){
        par[u]=v;
        rank[v]+=rank[u];
    }
    else{
        par[v]=u;
        rank[u]+=rank[v];
    }
  }

    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int dots=(n+1);
        vector<int>par(dots*dots),rank(dots*dots,1);
        for(int i=0;i<dots*dots;++i)par[i]=i;
        for(int i=0;i<=n;++i){
            for(int j=0;j<=n;++j){
                if(i==0 || j==0 || i==n || j==n){
                    unionSet(dots*i+j,0,par,rank);
                    // cout<<dots*i+j<<endl;
                }
            }
        }cout<<ans<<endl;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]=='/'){
                    int row=(dots*i)+j+1;
                    int col=(dots*(i+1))+j;
                    unionSet(row,col,par,rank);
                }
                else if(grid[i][j]=='\\'){
                    int row=(dots*i)+j;
                    int col=(dots*(i+1)+j+1);
                    unionSet(row,col,par,rank);
                }
            }
        }
        return ans;
    }
};