class TreeAncestor {
public:
  const int N=1e5;
unordered_map<int,vector<int>>adj;
   int level[100000];
   int table[31][100000];

   void dfs(int node,int par,int cnt){
    level[node]=cnt;
    table[0][node]=par;
    for(int i=1;i<31;++i){
        if(table[i-1][node]==-1)break;
        table[i][node]=table[i-1][table[i-1][node]];
    }

    for(auto nbr:adj[node]){
        if(nbr==par)continue;
        dfs(nbr,node,cnt+1);
    }
   }
    TreeAncestor(int n, vector<int>& parent) {
       memset(table,-1,sizeof(table)); 
       for(int i=1;i<n;++i){
        adj[i].push_back(parent[i]);
        adj[parent[i]].push_back(i);
       } 
       dfs(0,-1,0);
    }
    
    int getKthAncestor(int node, int k) {
        int ans=node;
        for(int i=0;i<=log2(k);++i){
            if(ans==-1)break;
            if(k&(1<<i))ans=table[i][ans];
        }
        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */