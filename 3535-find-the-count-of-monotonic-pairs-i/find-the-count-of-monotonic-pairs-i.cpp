class Solution {
public:
   int N=1e9+7;
   long long solve(int i,int prev1,int prev2,vector<int>& nums,vector<vector<vector<long long>>>&dp){
    if(i==nums.size())return 1;
    if(dp[i][prev1][prev2]!=-1)return dp[i][prev1][prev2];

    long long ans=0;
    for(int j=prev1;j<=nums[i];++j){
        if(nums[i]-j>=0 && nums[i]-j<=prev2)ans=(ans+solve(i+1,j,nums[i]-j,nums,dp))%N;
    }
    return dp[i][prev1][prev2]= ans;
   }
    int countOfPairs(vector<int>& nums) {
       int n=nums.size();
       vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(51,vector<long long>(51,-1)));
       long long ans=solve(0,0,50,nums,dp)%N;
       return (int)ans; 
    }
};