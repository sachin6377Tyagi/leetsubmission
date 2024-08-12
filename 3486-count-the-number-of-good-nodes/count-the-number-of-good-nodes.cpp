class Solution {
public:
// int ans=0;
   int dfs(int node,int par,unordered_map<int,vector<int>>&adj,vector<int>&dist){
    dist[node]=1;
    for(auto nbr:adj[node]){
        if(nbr==par)continue;
        dfs(nbr,node,adj,dist);
        dist[node]+=dist[nbr];
    }
    return dist[node];
   }
    int countGoodNodes(vector<vector<int>>& edges) {
       unordered_map<int,vector<int>>adj;
       int n=edges.size();
       for(int i=0;i<edges.size();++i){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
       }
       vector<int>dist(n+1);
       dfs(0,-1,adj,dist); 
       int ans=0;
       queue<int>q;
       q.push(0);
       unordered_map<int,bool>vis;
       vis[0]=1;
       while(q.size()){
        int node=q.front();
        q.pop();
        if(dist[node]==1)ans++;
        unordered_set<int>st;
        for(auto nbr:adj[node]){
            if(vis[nbr])continue;
            st.insert(dist[nbr]);
            q.push(nbr);
            vis[nbr]=1;
        }
        if(st.size()==1)ans++;
       }
       return ans;
    }
};