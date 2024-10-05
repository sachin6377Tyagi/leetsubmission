class Solution {
public:
   int solve(vector<int>&pre,int tar){
    unordered_map<int,int>mp;
    mp[0]=1;
    int ans=0,sum=0;
    for(int i=0;i<pre.size();++i){
        sum+=pre[i];
        if(mp.find(sum-tar)!=mp.end())ans+=mp[sum-tar];
        mp[sum]++;
    }
    return ans;
   }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;++i){
            vector<int>pre(m,0);
            for(int j=i;j<n;++j){
                for(int k=0;k<m;++k){
                    pre[k]+=matrix[j][k];
                }
                ans+=solve(pre,target);
                //cout<<ans<<endl;
            }
        }
        return ans;
    }
};