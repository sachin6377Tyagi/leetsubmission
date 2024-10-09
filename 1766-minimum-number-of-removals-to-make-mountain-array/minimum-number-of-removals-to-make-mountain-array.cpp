class Solution {
public:
   int dp[1005][1005][3];
    int solve(int i,int pre,int flag,vector<int>& nums){
        if(i==nums.size()){
            if(flag==0 || flag==2)return 1e9;
            else return 0;
        }
        if(dp[i][pre+1][flag]!=-1)return dp[i][pre+1][flag];

        int ans=1+solve(i+1,pre,flag,nums);
        if(pre==-1)ans=min(ans,solve(i+1,i,2,nums));
        else if(flag!=1){
            if(nums[i]-nums[pre]>0)ans=min(ans,solve(i+1,i,0,nums));
            else if(nums[i]-nums[pre]==0)ans=min(ans,1+solve(i+1,pre,flag,nums));
            else if(flag==0) ans=min(ans,solve(i+1,i,1,nums));
        }
        else{
            if(nums[i]-nums[pre]<0)ans=min(ans,solve(i+1,i,flag,nums));
            else ans=min(ans,1+solve(i+1,pre,flag,nums));
        }
        return dp[i][pre+1][flag]= ans;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,2,nums);
    }
};