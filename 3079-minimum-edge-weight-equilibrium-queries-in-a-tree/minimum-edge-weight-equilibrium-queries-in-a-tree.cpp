class Solution {
public:
   void dfs(int node,int par,int cnt,vector<int>&level,vector<vector<int>>&table,vector<vector<int>>&freq,unordered_map<int,vector<pair<int,int>>>&adj){
    level[node]=cnt;
    table[0][node]=par;
    for(int i=1;i<31;++i){
        if(table[i-1][node]==-1)break;
        table[i][node]=table[i-1][table[i-1][node]];
    }
    for(auto nbr:adj[node]){
        if(nbr.first==par)continue;
        freq[nbr.first]=freq[node];
        freq[nbr.first][nbr.second]++;
        dfs(nbr.first,node,cnt+1,level,table,freq,adj);
    }
   }

   int lca(int a,int b,vector<int>&level,vector<vector<int>>&table){
    if(level[b]<level[a])swap(a,b);
    int diff=level[b]-level[a];
    for(int i=0;i<31;++i){
        if(diff&(1<<i))b=table[i][b];
    }
    if(a==b)return a;
    for(int i=30;i>=0;i--){
        if(table[i][a]!=table[i][b]){
            a=table[i][a];
            b=table[i][b];
        }
    }
    return table[0][a];
   }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<int>ans;
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int>level(n+1);
        vector<vector<int>>table(31,vector<int>(n+1));
        vector<vector<int>>freq(n+1,vector<int>(30));
        dfs(0,-1,0,level,table,freq,adj);

        for(auto q:queries){
            int a=q[0],b=q[1];
            int c=lca(a,b,level,table);
            vector<int>f(30);
            for(int i=0;i<30;++i){
                f[i]=freq[a][i]+freq[b][i]-2*freq[c][i];
            }
            int sum=0,maxi=0;
            for(int i=0;i<30;++i){
                sum+=f[i];
                maxi=max(maxi,f[i]);
            }
            cout<<sum<<" "<<maxi<<endl;
            ans.push_back(sum-maxi);
        }
        return ans;
    }
};