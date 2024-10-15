class Solution {
public:
   int dp[3005][3005];
   int solve(int i,int j,string &src, string &patt,unordered_set<int>&st,int n,int m){
    if(i==n){
        if(j==m){
            return 0;
        }
        return INT_MIN;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=-1e9;
    ans=max(ans,solve(i+1,j,src,patt,st,n,m));
    if(st.count(i))ans=max(ans,1+solve(i+1,j,src,patt,st,n,m));
    if(src[i]==patt[j])ans=max(ans,solve(i+1,j+1,src,patt,st,n,m));
    return dp[i][j]=ans;
   }
    int maxRemovals(string src, string patt, vector<int>& targetIndices) {
        int n=src.size(),m=patt.size();
        unordered_set<int>st(targetIndices.begin(),targetIndices.end());
        memset(dp,-1,sizeof(dp));
       return solve(0,0,src,patt,st,n,m);
    }
};