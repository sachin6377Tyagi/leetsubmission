class Solution {
public:
   int dp[100005][3][2];
   int solve(int i,int curr,int sum,string &s){
    if(i==s.size()){
        if(sum==0)return 0;
        return 1e9;
    }
    if(dp[i][curr+1][sum]!=-1)return dp[i][curr+1][sum];
    int ans=1e9;
    bool flag=curr!=s[i]-'0';
    if(sum==0){
        ans=min(ans,flag+solve(i+1,curr,1,s));
        ans=min(ans,solve(i+1,s[i]-'0',1,s));
    }
    else{
         ans=min(ans,flag+solve(i+1,curr,0,s));
    }
    return dp[i][curr+1][sum]=ans;
   }
    int minChanges(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,0,s);
    }
};