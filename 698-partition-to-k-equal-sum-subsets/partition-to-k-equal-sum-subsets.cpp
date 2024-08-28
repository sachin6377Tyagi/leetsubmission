class Solution {
public:
    bool solve(int mask,int x,int sum,int n,int k,vector<int>& nums, int len,vector<int>&dp){
        if(x==k)return true;
        if(mask==(1<<n)-1)return true;
        if(dp[mask]!=-1)return dp[mask];

        bool ans=false;
        for(int i=0;i<n;++i){
            if((mask&(1<<i))==0){
                sum+=nums[i];
                if(sum<len)ans=ans|solve(mask|(1<<i),x,sum,n,k,nums,len,dp);
                else if(sum==len)ans=ans|solve(mask|(1<<i),x+1,0,n,k,nums,len,dp);
                sum-=nums[i];
            }
        }
        return dp[mask]= ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;++i)sum+=nums[i];
        if(sum%k)return false;
        sort(nums.begin(),nums.end());
        vector<int>dp((1<<n),-1);
        return solve(0,0,0,n,k,nums,sum/k,dp);
    }
};