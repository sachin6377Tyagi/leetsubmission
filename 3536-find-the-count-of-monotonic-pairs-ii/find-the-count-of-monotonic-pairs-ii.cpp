class Solution {
public:
int N=1e9+7;
//    long long solve(int i,int prev1,vector<int>& nums,vector<vector<long long>>&dp){
//     if(i==nums.size())return 1;
//     if(dp[i][prev1]!=-1)return dp[i][prev1];

//     long long ans=0;
//     int prev2=1001;
//     if(i>0)prev2=nums[i-1]-prev1;
//     for(int j=prev1;j<=nums[i];++j){
//         if(nums[i]-j<=prev2)ans=(ans+solve(i+1,j,nums,dp))%N;
//     }
//     return dp[i][prev1]=ans;
//    } 
    
    int countOfPairs(vector<int>& nums) {
        int n=nums.size();
    //    vector<vector<long long>>dp(n,vector<long long>(1001,-1));
    //    long long ans=solve(0,0,nums,dp)%N;
    //    return (int)ans; 
    vector<long long>dp(2001,1);
    for(int i=n-1;i>=0;i--){
        vector<long long>pre(2001,0);
        vector<long long>newDp(2001,0);
       pre[0]=dp[0];
       for(int j=1;j<2001;++j)pre[j]=pre[j-1]+dp[j];
       for(int prev1=0;prev1<=2000;++prev1){
        int prev2=1e9;
        if(i>0)prev2=nums[i-1]-prev1;
        if(prev2<0)break;
        int l=max(prev1,nums[i]-prev2);
        int r=nums[i];
        if(l<=r){
            newDp[prev1]=(pre[r]-(l>0?pre[l-1]:0)+N)%N;
        }
       }
       dp=newDp;
    }
    return dp[0];
    }
};