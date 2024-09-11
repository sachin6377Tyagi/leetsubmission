class Solution {
public:
    int minOperations(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       vector<int>pre(n);
       pre[0]=1;
       for(int i=1;i<n;++i){
        if(nums[i]==nums[i-1])pre[i]=pre[i-1];
        else pre[i]=pre[i-1]+1;
       } 
       int ans=1e9;
       for(int i=0;i<n;++i){
        int ub=upper_bound(nums.begin(),nums.end(),nums[i]+n-1)-nums.begin();
        int sum=i+(n-ub);
        ub--;
        int d=0;
        d+=pre[ub];
        if(i>0)d-=pre[i-1];
        sum+=((ub-i+1)-d);
        ans=min(ans,sum);
       }
       return ans;
    }
};