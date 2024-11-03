class Solution {
public:
   unordered_map<int,int>freq;
    void dfs(int node,int par,unordered_map<int,vector<pair<int,char>>>&adj,int sum){
        freq[sum]++;
        for(auto it:adj[node]){
            if(it.first==par)continue;
            int x=it.second-'a';
            sum^=(1<<x);
            dfs(it.first,node,adj,sum);
            sum^=(1<<x);
        }
    }
    long long countPalindromePaths(vector<int>& parent, string s) {
        unordered_map<int,vector<pair<int,char>>>adj;
        int n=parent.size();
        for(int i=1;i<n;++i){
            adj[parent[i]].push_back({i,s[i]});
        }
        dfs(0,-1,adj,0);
        long long ans=0;
        for(auto it:freq){
            long long val=it.first,cnt=it.second;
            for(int j=0;j<26;++j){
                long long other=val^(1<<j);
                if(freq.find(other)==freq.end())continue;
                ans+=(freq[other]*cnt);
            }
            ans+=(cnt*(cnt-1));
        }
        return ans/2;
    }
};