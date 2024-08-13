class Solution {
public:
   int temp=0;
   void dfs(int node,int par,int d,unordered_map<int,vector<pair<int,int>>>&adj,int sp){
    if(d%sp==0)temp++;
    for(auto nbr:adj[node]){
        if(nbr.first==par)continue;
        dfs(nbr.first,node,nbr.second+d,adj,sp);
    }
   }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
       int n=edges.size()+1; 
       vector<int>ans(n);
       unordered_map<int,vector<pair<int,int>>>adj;
       for(int i=0;i<edges.size();++i){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
       }
       for(int i=0;i<n;++i){
        if(adj[i].size()>1){
            int res=0;
            vector<int>tree;
            for(auto nbr:adj[i]){
                dfs(nbr.first,i,nbr.second,adj,signalSpeed);
                if(temp==0)continue;
                tree.push_back(temp);
                temp=0;
            }
            if(tree.size()>1){
                for(int k=0;k<tree.size();++k){
                    for(int j=k+1;j<tree.size();++j){
                        res+=(tree[k]*tree[j]);
                    }
                }
                ans[i]=res;
            }
            else ans[i]=0;
        }
        else ans[i]=0;
       }
       return ans;
    }
};