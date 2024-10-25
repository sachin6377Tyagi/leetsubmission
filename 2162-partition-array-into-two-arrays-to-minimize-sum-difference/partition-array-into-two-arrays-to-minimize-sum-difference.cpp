class Solution {
public:
    vector<pair<int,int>>divideArray(int lo,int hi,int n,vector<int>&nums){
        vector<pair<int,int>>ans;
        int len=(1<<n);
        for(int i=0;i<len;++i){
            pair<int,int>p={0,0};
            for(int j=0;j<n;++j){
                if(i&(1<<j)){
                    p.first+=nums[j+lo];
                    p.second++;
                }
            }
            ans.push_back(p);
        }
        return ans;
    }
    int minimumDifference(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();++i)sum+=nums[i];
        int n=nums.size();
        n=n/2;
        vector<pair<int,int>>left=divideArray(0,n,n,nums);
        vector<pair<int,int>>right=divideArray(n,2*n,n,nums);
        sort(right.begin(),right.end());
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<right.size();++i){
            mp[right[i].second].push_back(right[i].first);
        }
        int ans=1e9;
        for(int i=0;i<left.size();++i){
            int num=left[i].first;
            int l1=left[i].second;
            int ind=lower_bound(mp[n-l1].begin(),mp[n-l1].end(),sum/2-num)-mp[n-l1].begin();
            if(ind!=mp[n-l1].size()){
                int sum1=num+mp[n-l1][ind];
                int sum2=sum-sum1;
                ans=min(ans,abs(sum1-sum2));
            }
        }
        return ans;
    }
};