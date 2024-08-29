class Solution {
public:
   pair<int,int> solve(int mask,int x,vector<int>&arr,vector<pair<int,int>>&dp){
    int n=arr.size();
    if(mask==0)return {1,0};
    pair<int,int>p={0,0};
    if(dp[mask]!=p)return dp[mask];

    pair<int,int>ans={n+1,0};
    for(int i=0;i<n;++i){
        if((1<<i)&mask){
            pair<int,int>curr=solve(mask^(1<<i),x,arr,dp);
            if(curr.second+arr[i]<=x){
                curr.second+=arr[i];
            }
            else{
                curr.second=arr[i];
                curr.first++;
            }
            ans=min(ans,curr);
        }
    }
    return dp[mask]=ans;
   }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n=jobs.size();
        int lo=0,hi=0;
        for(int i=0;i<n;++i){
            lo=max(lo,jobs[i]);
            hi+=jobs[i];
        }
        int ans;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            vector<pair<int,int>>dp((1<<n),{0,0});
            int num=solve((1<<n)-1,mid,jobs,dp).first;
           // cout<<num<<" "<<mid<<endl;
            if(num<=k){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};