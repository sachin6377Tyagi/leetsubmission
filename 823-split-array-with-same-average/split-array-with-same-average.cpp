class Solution {
public:
    vector<pair<int,int>>meetInMiddle(int lo,int n,vector<int>&nums){
        vector<pair<int,int>>ans;
        int len=(1<<n);
        for(int i=0;i<len;++i){
            pair<int,int>p={0,0};
            for(int j=0;j<n;++j){
                if((1<<j)&i){
                    p.first+=nums[j+lo];
                    p.second++;
                }
            }
            ans.push_back(p);
        }
        return ans;
    }
    bool splitArraySameAverage(vector<int>& nums) {
        int n=nums.size();
        int l1=n/2;
        int l2=n-l1;
        vector<pair<int,int>>left=meetInMiddle(0,l1,nums);
        vector<pair<int,int>>right=meetInMiddle(l1,l1,nums);
        int sum=0;
        for(int i=0;i<n;++i)sum+=nums[i];
        unordered_map<int,set<int>>mp;
        for(int i=0;i<right.size();++i){
            mp[right[i].second].insert(right[i].first);
        }
        for(int l=1;l<n;++l){
            for(int i=0;i<left.size();++i){
                int l1=left[i].second;
                if(l-l1<0 || (sum*l)%n)continue;
                int l2=l-l1;
                int s1=(sum*l)/n;
                int s2=s1-left[i].first;
                if(s2<0)continue;
                if(mp[l2].find(s2)!=mp[l2].end())return true;
            }
        }
        return false;
        
    }
};