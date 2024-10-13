class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
       int n=nums.size();
       vector<int>ans(n);
       for(int i=0;i<n;++i){
        int a=-1;
        for(int j=1;j<nums[i];++j){
            if((j|j+1)==nums[i]){
                a=j;
                break;
            }
        }
        ans[i]=a;
       } 
       return ans;
    }
};