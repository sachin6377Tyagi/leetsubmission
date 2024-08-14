class Solution {
public:
    int dfs(int node,int par,unordered_map<int,vector<int>>&adj,vector<bool>&apple){
        int cnt=0;
        for(auto nbr:adj[node]){
            if(nbr==par)continue;
           int num=dfs(nbr,node,adj,apple);
            if(apple[nbr]){
                cout<<node<<" "<<nbr<<" "<<apple[nbr]<<endl;
                num+=2;
                cnt+=num;
                apple[node]=1;
            }
        }
        return cnt;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        //if(hasApple[0])ans-=2;
        return dfs(0,-1,adj,hasApple);
    }
};