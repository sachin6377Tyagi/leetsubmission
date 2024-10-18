class Solution {
public:
    int solve(int i,int sum,int tar,vector<int>& nums,int n){
        if(i==n){
            if(sum==tar)return 1;
            return 0;
        }
        int ans=solve(i+1,sum,tar,nums,n);
        ans+=solve(i+1,sum|nums[i],tar,nums,n);
        return ans;
    }
    int countMaxOrSubsets(vector<int>& nums) {
       int tar=0;
       for(int i=0;i<nums.size();++i)tar=tar|nums[i];
       return solve(0,0,tar,nums,nums.size()); 
    }
};