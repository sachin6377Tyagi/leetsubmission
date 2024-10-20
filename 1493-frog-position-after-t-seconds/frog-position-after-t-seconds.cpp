class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int tar) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<double>dist(n+1);
        vector<int>level(n+1);
        int lev=1;
        queue<pair<int,double>>q;
        q.push({1,1.0});
        level[1]=0;
        dist[1]=1;
        unordered_map<int,bool>vis;
        vis[1]=1;
        while(q.size()){
            int l=q.size();
            while(l--){
                auto p=q.front();
                q.pop();
                int node=p.first;
                double prob=p.second;
                int len=adj[node].size();
                if(node!=1)len--;
                for(auto nbr:adj[node]){
                    if(!vis[nbr]){
                        q.push({nbr,prob/(len*1.0)});
                        dist[nbr]=prob/(len*1.0);
                        level[nbr]=lev;
                        vis[nbr]=1;
                    }
                }
            }
            lev++;
        }
        if(tar==1){
            if(adj[tar].size()==0 && t>=level[tar])return dist[tar];
            if(adj[tar].size()>0 && t==level[tar])return dist[tar];
             return 0.00000;
        }
        if(adj[tar].size()==1 && t>=level[tar])return dist[tar];
        if(adj[tar].size()>1 && t==level[tar])return dist[tar];
        return 0.00000;
    }
};