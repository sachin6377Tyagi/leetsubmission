class Solution {
public:
   const int N=1e9+7;
   long long dp[51][101][51];
   long long solve(int i,int prev,int k,int n,int m){
    if(i==n){
        if(k==0)return 1;
        return 0;
    }
    if(dp[i][prev][k]!=-1)return dp[i][prev][k];

    long long ans=0;
    for(int j=1;j<=m;++j){
        if(j>prev && k>0)ans=(ans+solve(i+1,j,k-1,n,m))%N;
        else if(j<=prev)ans=(ans+solve(i+1,prev,k,n,m))%N;
    }
    return dp[i][prev][k]= ans%N;
   }
    int numOfArrays(int n, int m, int k) {
        if(k==0)return 0;
        long long ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=m;++i){
            ans=(ans+solve(1,i,k-1,n,m))%N;
        }
        return ans;
    }
};