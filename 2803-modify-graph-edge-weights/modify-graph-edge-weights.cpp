class Solution {
public:
  int dijkstra(int n, unordered_map<int,vector<pair<int,int>>>&adj,int src,int dest){
    vector<int>dist(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    dist[src]=0;
    while(pq.size()){
        auto it=pq.top();
        pq.pop();
        int node=it.second,d=it.first;
        if(dist[node]<d)continue;
        for(auto nbr:adj[node]){
            if(d+nbr.second<dist[nbr.first]){
                pq.push({d+nbr.second,nbr.first});
                dist[nbr.first]=d+nbr.second;
            }
        }
    }
    return dist[dest];
  }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edg, int src, int dest, int tar) {
        unordered_map<int,vector<pair<int,int>>>adj;
        int m=edg.size();
        for(int i=0;i<m;++i){
            if(edg[i][2]!=-1){
                adj[edg[i][0]].push_back({edg[i][1],edg[i][2]});
                adj[edg[i][1]].push_back({edg[i][0],edg[i][2]});
            }
        }
        int init=dijkstra(n,adj,src,dest);
        bool flag=0;
        if(init<tar)return {};
        else if(init==tar)flag=1;
        for(int i=0;i<m;++i){
            if(edg[i][2]!=-1)continue;
            if(flag){
                edg[i][2]=2e9;
            }
            else edg[i][2]=1;
            adj[edg[i][0]].push_back({edg[i][1],edg[i][2]});
            adj[edg[i][1]].push_back({edg[i][0],edg[i][2]});
            if(!flag){
                int d=dijkstra(n,adj,src,dest);
                //cout<<i<<" "<<d<<endl;
                 if(d<=tar){
                   int diff=tar-d;
                    //cout<<diff<<endl;
                    edg[i][2]+=diff;
                    flag=1;
               }
            }
        }
        if(!flag)return {};
        return edg;
    }
};