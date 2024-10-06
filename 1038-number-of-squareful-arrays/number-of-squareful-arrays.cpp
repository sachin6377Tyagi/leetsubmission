class Solution {
public:
   set<vector<int>>st;
   bool isSquare(long long a,long long b){
    long long sq=sqrtl(a+b);
    return (sq*sq)==(a+b);
   }
   int solve(int i,int mask,vector<int>& nums,int n){
    if(mask==(1<<n)-1){
        return 1;
    }

   int ans=0;
    for(int j=0;j<n;++j){
        if(!(mask&(1<<j))){
            if(j>0 && nums[j]==nums[j-1] && !(mask&(1<<(j-1))))continue;
            if(i==-1 || isSquare(nums[i],nums[j]))ans+=solve(j,mask|(1<<j),nums,n);
        }
    }
    return ans;
   }
    int numSquarefulPerms(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        return solve(-1,0,nums,n);
    }
};