class Solution {
public:
    bool solve(int mask,int side,int sum,int n,vector<int>&arr,int len,vector<int>&dp){
        if(side==4)return true;
        if(mask==(1<<n)-1)return true;
        if(dp[mask]!=-1)return dp[mask];

        bool ans=false;
        for(int i=0;i<n;++i){
            if((mask&(1<<i))==0){
                sum+=arr[i];
                if(sum<len)ans=ans|solve(mask|(1<<i),side,sum,n,arr,len,dp);
                else if(sum==len)ans=ans|solve(mask|(1<<i),side+1,0,n,arr,len,dp);
                sum-=arr[i];
            }
        }
        return dp[mask]= ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0,n=matchsticks.size();
        for(auto a:matchsticks)sum+=a;
        if(sum%4)return false;
        sort(matchsticks.begin(),matchsticks.end());
        vector<int>dp(1<<n,-1);
        return solve(0,0,0,n,matchsticks,sum/4,dp);
    }
};