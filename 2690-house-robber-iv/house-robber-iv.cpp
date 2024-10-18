class Solution {
public:
   bool isPossible(int mid,vector<int>&nums,int k){
    int cnt=0;
    int i=0;
    while(i<nums.size()){
        if(nums[i]<=mid){
            cnt++;
            i+=2;
        }
        else i++;
    }
    return cnt>=k;
   }
    int minCapability(vector<int>& nums, int k) {
        int lo=1e9,hi=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            lo=min(lo,nums[i]);
            hi=max(hi,nums[i]);
        }
        int ans=1e9;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(isPossible(mid,nums,k)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};