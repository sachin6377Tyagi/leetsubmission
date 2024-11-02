class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
       int n=nums.size();
       sort(nums.begin(),nums.end());
       int ans=0;
       int i=0,j=0;
       while(j<n){
        if(nums[j]>nums[i]){
            ans++;
            i++;
            j++;
        }
        else j++;
       }
       return ans;
    }
};