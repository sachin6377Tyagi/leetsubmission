class Solution {
public:
   int dp[1001][1001][3];
   int solve(int i,int pre,int flag,vector<int>&nums){
    if(i==nums.size())return 0;
    if(dp[i][pre][flag]!=-1)return dp[i][pre][flag];
    int ans=solve(i+1,pre,flag,nums);
    if(flag!=0){
        if(nums[i]-pre<0)ans=max(ans,1+solve(i+1,nums[i],0,nums));
    }
    if(flag!=1){
        if(nums[i]-pre>0)ans=max(ans,1+solve(i+1,nums[i],1,nums));
    }
    return dp[i][pre][flag]= ans;
   }
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1)return 1;
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<nums.size();++i){
            ans=max(ans,solve(i+1,nums[i],2,nums));
        }
        return ans+1;
    }
};