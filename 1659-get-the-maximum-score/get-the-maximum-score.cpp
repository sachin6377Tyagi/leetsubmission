class Solution {
public:
map<int,int>mp1;
map<int,int>mp2;
const int N=1e9+7;
long long dp[100005][2];
   long long solve(int i,int flag,vector<int>& nums1, vector<int>& nums2){
    if(flag==0 && i>=nums1.size())return 0;
    if(flag==1 && i>=nums2.size())return 0;
    if(dp[i][flag]!=-1)return dp[i][flag];

    if(flag==0){
        long long ans2=0;
        long long ans1=nums1[i]+solve(i+1,0,nums1,nums2);
        if(mp2.find(nums1[i])!=mp2.end())ans2=nums1[i]+solve(mp2[nums1[i]],1,nums1,nums2);
        return dp[i][flag]=max(ans1,ans2);
    }
    else{
        long long ans1=nums2[i]+solve(i+1,1,nums1,nums2);
        long long ans2=0;
        if(mp1.find(nums2[i])!=mp1.end())ans2=nums2[i]+solve(mp1[nums2[i]],0,nums1,nums2);
        return dp[i][flag]=max(ans1,ans2);
    }
   }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();++i)mp1[nums1[i]]=i+1;
        for(int i=0;i<nums2.size();++i)mp2[nums2[i]]=i+1;
        memset(dp,-1,sizeof(dp));
        return max(solve(0,0,nums1,nums2)%N,solve(0,1,nums1,nums2)%N);
    }
};