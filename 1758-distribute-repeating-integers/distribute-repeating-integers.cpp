class Solution {
public:
   int dp[51][1<<10];
   bool isPossible(int newMask,int mask,int num,int n,vector<int>&quant){
    if(mask&newMask)return false;

    int sum=0;
    for(int i=0;i<n;++i){
        if((1<<i)&newMask)sum+=quant[i];
    }
    return sum<=num;
   }
    bool solve(int i,int mask,vector<int>&vec,vector<int>& quant,int n){
        if(mask==(1<<n)-1)return true;
        if(i==vec.size())return false;
        if(dp[i][mask]!=-1)return dp[i][mask];
        bool ans=0;
        for(int j=0;j<(1<<n);++j){
            if(isPossible(j,mask,vec[i],n,quant)){
                ans=ans|solve(i+1,mask|j,vec,quant,n);
            }
        }
        return dp[i][mask]= ans;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quant) {
        map<int,int>mp;
        for(auto a:nums)mp[a]++;
        vector<int>vec;
        for(auto it:mp)vec.push_back(it.second);
        memset(dp,-1,sizeof(dp));
        return solve(0,0,vec,quant,quant.size());
    }
};