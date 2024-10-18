class Solution {
public:
   int dp[17][1000000];
    int solve(int i,int sum,int tar,vector<int>& nums,int n){
        if(i==n){
            if(sum==tar)return 1;
            return 0;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int ans=solve(i+1,sum,tar,nums,n);
        ans+=solve(i+1,sum|nums[i],tar,nums,n);
        return dp[i][sum]= ans;
    }
    int countMaxOrSubsets(vector<int>& nums) {
       int tar=0;
       for(int i=0;i<nums.size();++i)tar=tar|nums[i];
       memset(dp,-1,sizeof(dp));
       return solve(0,0,tar,nums,nums.size()); 
    }
};