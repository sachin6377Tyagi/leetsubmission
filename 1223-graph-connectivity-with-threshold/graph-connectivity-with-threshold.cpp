class Solution {
public:
   int findPar(int u,vector<int>&par){
    if(par[u]==u)return u;
    return par[u]=findPar(par[u],par);
   }

   void unionSet(vector<int>&par,vector<int>&rank,int u,int v){
    u=findPar(u,par);
    v=findPar(v,par);
    if(u==v)return;
    if(rank[u]<=rank[v]){
        par[u]=v;
        rank[v]+=u;
    }
    else{
        par[v]=u;
        rank[u]+=v;
    }
   }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<int>par(n+1);
        for(int i=1;i<=n;++i)par[i]=i;
        vector<int>rank(n+1,0);
        for(int i=threshold+1;i<=n;++i){
            for(int j=2*i;j<=n;j+=i){
                unionSet(par,rank,i,j);
            }
        }
        for(auto q:queries){
            int u=q[0],v=q[1];
            int pu=findPar(u,par),pv=findPar(v,par);
            if(pu==pv){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};