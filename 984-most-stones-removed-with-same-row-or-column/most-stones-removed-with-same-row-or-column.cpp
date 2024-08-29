class Solution {
public:
   bool isPossible(int i,int j,vector<vector<int>>& stones){
    if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])return true;
    else return false;
   }
   void dfs(int node,vector<bool>&vis,vector<vector<int>>& stones){
    vis[node]=1;

    for(int i=0;i<stones.size();++i){
        if(!vis[i] && isPossible(node,i,stones))dfs(i,vis,stones);
    }
   }
    int removeStones(vector<vector<int>>& stones) {
       int n=stones.size();
       vector<bool>vis(n,0);
       int comp=0;
       for(int i=0;i<n;++i){
        if(!vis[i]){
            comp++;
            dfs(i,vis,stones);
        }
       }

       return n-comp; 
    }
};