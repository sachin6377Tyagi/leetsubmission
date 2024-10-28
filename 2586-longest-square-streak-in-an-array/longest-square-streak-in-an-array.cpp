class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int,int>mp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            int x=sqrt(nums[i]);
            if((x*x)==nums[i]){
                //cout<<x*x<<" "<<nums[i]<<endl;
                mp[nums[i]]=mp[x]+1;
            }
            else mp[nums[i]]=1;
        }
        int ans=1;
        for(auto it:mp)ans=max(ans,it.second);
        if(ans==1)return -1;
        return ans;
    }
};