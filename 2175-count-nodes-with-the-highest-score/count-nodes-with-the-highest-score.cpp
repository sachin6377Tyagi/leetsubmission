class Solution {
public:
   int dfs(int node,vector<int>& par,unordered_map<int,vector<int>>&adj,vector<int>&cnt){
    int ans=1;
    for(auto nbr:adj[node]){
        cnt[nbr]=dfs(nbr,par,adj,cnt);
        ans+=cnt[nbr];
    }
    return ans;
   }
    int countHighestScoreNodes(vector<int>& parents) {
        unordered_map<int,vector<int>>adj;
        int n=parents.size();
        for(int i=1;i<n;++i){
            adj[parents[i]].push_back(i);
        }
        vector<int>cnt(n,0);
       cnt[0]= dfs(0,parents,adj,cnt);
        //for(int i=0;i<n;++i)cout<<cnt[i]<<" ";
        map<long long,long long>mp;
        long long maxi=0;
        for(int i=0;i<n;++i){
            vector<long long>temp;
            for(auto nbr:adj[i]){
                temp.push_back(cnt[nbr]);
            }
            if(parents[i]!=-1)temp.push_back(cnt[0]-cnt[i]);
            long long ans=1;
            for(auto a:temp)ans=(ans*a);
            mp[ans]++;
            maxi=max(maxi,ans);
        }
        return mp[maxi];
    }
};