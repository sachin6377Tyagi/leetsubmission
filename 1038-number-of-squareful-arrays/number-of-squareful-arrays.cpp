class Solution {
public:
   set<vector<int>>st;
   int dp[13][1<<12];
   bool isSquare(long long a,long long b){
    long long sq=sqrtl(a+b);
    return (sq*sq)==(a+b);
   }
   int solve(int i,int mask,vector<int>& nums,int n){
    if(mask==(1<<n)-1){
        return 1;
    }
    if(dp[i+1][mask]!=-1)return dp[i+1][mask];

   int ans=0;
    for(int j=0;j<n;++j){
        if(!(mask&(1<<j))){
            if(j>0 && nums[j]==nums[j-1] && !(mask&(1<<(j-1))))continue;
            if(i==-1 || isSquare(nums[i],nums[j]))ans+=solve(j,mask|(1<<j),nums,n);
        }
    }
    return dp[i+1][mask]= ans;
   }
    int numSquarefulPerms(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        return solve(-1,0,nums,n);
    }
};