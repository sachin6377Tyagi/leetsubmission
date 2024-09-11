class Solution {
public:
  int findPar(int u,vector<int>&par){
    if(par[u]==u)return u;
    return par[u]=findPar(par[u],par);
  }

  void unionSet(int u,int v,vector<int>&par,vector<long long>&rank){
    u=findPar(u,par);
    v=findPar(v,par);
    if(u==v)return;
    par[v]=u;
    // if(rank[u]>=rank[v]){
    //     rank[u]+=rank[v];
    //     par[v]=u;
    // }
    // else{
    //     rank[v]+=rank[u];
    //     par[u]=v;
    // }
  }
    bool gcdSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>par(1e5+1);
        vector<long long>rank(1e5,1);
        for(int i=1;i<=1e5;++i)par[i]=i;
        set<int>st;

        for(int i=0;i<n;++i){
            for(int j=2;j<=sqrt(nums[i]);++j){
                if(nums[i]%j==0){
                    unionSet(nums[i],j,par,rank);
                    unionSet(nums[i]/j,j,par,rank);
                }
            }
        }
       vector<int>temp=nums;
       sort(temp.begin(),temp.end());
       for(int i=0;i<n;++i){
        if(nums[i]!=temp[i]){
            if(findPar(nums[i],par)!=findPar(temp[i],par))return false;
        }
       }
       return true;
    }
};