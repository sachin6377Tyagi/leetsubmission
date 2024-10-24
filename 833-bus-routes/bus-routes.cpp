class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        unordered_map<int,vector<int>>buses;
        for(int i=0;i<routes.size();++i){
            for(int j=0;j<routes[i].size();++j){
                buses[routes[i][j]].push_back(i);
            }
        }
        queue<int>q;
        unordered_map<int,bool>vis;
        for(auto it:buses[source]){
            q.push(it);
            vis[it]=1;
        }
        // bus[source]=1;
        int lev=1;
        while(q.size()){
            int l=q.size();
            while(l--){
                int bus=q.front();
                q.pop();
                for(auto route:routes[bus]){
                    if(route==target)return lev;
                    for(auto b:buses[route]){
                        if(!vis[b]){
                            q.push(b);
                            vis[b]=1;
                        }
                    }
                }
            }
            lev++;
        }
        return -1;
    }
};