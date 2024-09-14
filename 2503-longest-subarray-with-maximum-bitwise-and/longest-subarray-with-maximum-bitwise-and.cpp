class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0,n=nums.size();
        for(int i=0;i<n;++i)maxi=max(maxi,nums[i]);
        int ans=1,cnt=0;
        for(int i=0;i<n;++i){
            if(nums[i]==maxi)cnt++;
            else{
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};