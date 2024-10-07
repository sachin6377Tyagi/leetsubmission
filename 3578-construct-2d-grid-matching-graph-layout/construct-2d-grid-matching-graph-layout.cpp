class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
       vector<int>deg(n,0);
       unordered_map<int,vector<int>>adj;
       for(int i=0;i<edges.size();++i){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
        deg[edges[i][0]]++;
        deg[edges[i][1]]++;
       }
       vector<int>curr;
       vector<bool>vis(n,0);
       int x=min_element(deg.begin(),deg.end())-deg.begin();
       curr.push_back(x);
       vis[x]=1;
       while(curr.size()){
        int node=curr.back();
        if(curr.size()>=2 && deg[node]==deg[x])break;
        int nebr,dg=5;
        for(auto nbr:adj[node]){
            if(vis[nbr])continue;
            if(deg[nbr]<dg){
                dg=deg[nbr];
                nebr=nbr;
            }
        }
        curr.push_back(nebr);
        vis[nebr]=1;
       }
       int col=curr.size(),row=n/col;
       vector<vector<int>>ans(row);
       ans[0]=curr;
       for(int i=1;i<row;++i){
        vector<int>temp;
        for(int j=0;j<col;++j){
            for(auto nbr:adj[ans[i-1][j]]){
                if(!vis[nbr]){
                    vis[nbr]=1;
                    temp.push_back(nbr);
                    break;
                }
            }
        }
        ans[i]=temp;
       }
       return ans;
    }
};