class Solution {
public:
map<int,int>mp1;
map<int,int>mp2;
const int N=1e9+7;
long long dp[100005][2];
   long long solve(int i,int flag,vector<int>& nums1, vector<int>& nums2){
    if(flag==0 && i==nums1.size())return 0;
    if(flag==1 && i==nums2.size())return 0;
    if(dp[i][flag]!=-1)return dp[i][flag];

    long long ans=0;
    if(flag==0){
        ans=max(ans,(long long)nums1[i]+solve(i+1,flag,nums1,nums2));
        if(mp2[nums1[i]]>0)ans=max(ans,nums1[i]+solve(mp2[nums1[i]],1,nums1,nums2));
    }
    else{
        ans=max(ans,nums2[i]+solve(i+1,flag,nums1,nums2));
        if(mp1[nums2[i]]>0)ans=max(ans,nums2[i]+solve(mp1[nums2[i]],0,nums1,nums2));
    }
    return dp[i][flag]= ans;
   }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();++i)mp1[nums1[i]]=i+1;
        for(int i=0;i<nums2.size();++i)mp2[nums2[i]]=i+1;
        memset(dp,-1,sizeof(dp));
        return max(solve(0,0,nums1,nums2)%N,solve(0,1,nums1,nums2)%N);
    }
};