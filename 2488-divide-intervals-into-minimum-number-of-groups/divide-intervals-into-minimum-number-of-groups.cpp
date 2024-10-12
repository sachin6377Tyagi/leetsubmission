class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>arr(1e6+10,0);
        for(auto a:intervals){
            arr[a[0]]++;
            arr[a[1]+1]--;
        }
        for(int i=1;i<=1e6;++i)arr[i]+=arr[i-1];
        int ans=0;
        for(int i=1;i<=1e6;++i)ans=max(ans,arr[i]);
        return ans;
    }
};