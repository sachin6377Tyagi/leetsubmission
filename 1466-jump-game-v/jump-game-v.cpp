class Solution {
public:
   int solve(int i,int d,vector<int>& arr,vector<int>&dp){
    int n=arr.size();
    if(i==n || i<0)return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=0;
    for(int j=i+1;j<min(n,i+1+d);++j){
        if(arr[j]>=arr[i])break;
        ans=max(ans,1+solve(j,d,arr,dp));
    }
    for(int j=i-1;j>max(-1,i-1-d);j--){
        if(arr[j]>=arr[i])break;
        ans=max(ans,1+solve(j,d,arr,dp));
    }
    return dp[i]= ans;
   }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int>dp(n,-1);
        int ans=0;
        for(int i=0;i<n;++i){
            if(dp[i]==-1){
                ans=max(ans,solve(i,d,arr,dp));
            }
            else ans=max(ans,dp[i]);
        }
        return ans+1;
    }
};