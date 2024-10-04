class Solution {
public:
    int maximumXOR(vector<int>& nums) {
       int ans=0;
       for(int j=31;j>=0;j--){
        for(int i=0;i<nums.size();++i){
            if(nums[i]&(1<<j)){
                ans+=(1<<j);
                break;
            }
        }
       } 
       return ans;
    }
};