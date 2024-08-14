class Solution {
public:
   bool isPossible(vector<int>& nums,int mid,int k){
    int cnt=0,left=0;
    for(int i=1;i<nums.size();++i){
        while(nums[i]-nums[left]>mid)left++;
        cnt+=(i-left);
    }
    return (cnt>=k);
   }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int lo=0,hi=nums[n-1]-nums[0];
        int ans=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(isPossible(nums,mid,k)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};