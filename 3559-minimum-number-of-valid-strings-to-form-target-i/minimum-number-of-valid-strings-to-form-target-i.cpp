struct Trie{
    Trie* child[26];
    bool wordEnd=false;
};

class Solution {
public:
   void insert(Trie* root,string &a){
    Trie* curr=root;
    for(int i=0;i<a.size();++i){
        int x=a[i]-'a';
        if(curr->child[x]==nullptr){
            //cout<<a[i]<<" ";
            Trie* node=new Trie();
            curr->child[x]=node;
        }
        curr=curr->child[x];
    }
    curr->wordEnd=true;
   }

   int solve(int i,string &target,Trie* root,vector<int>&dp){
    int n=target.size();
    if(i>=n) return 0;
    if(dp[i]!=-1)return dp[i];

    int ans=1e6;
    Trie* curr=root;
    int x=i;
    while(x<n && curr->child[target[x]-'a']){
    //    cout<<target[x]<<" ";
        ans=min(ans,1+solve(x+1,target,root,dp));
        curr = curr->child[target[x]-'a'];
        x++;
    }
    return dp[i]= ans;
   }
    int minValidStrings(vector<string>& words, string target) {
        Trie* root=new Trie();
        for(auto a:words) insert(root,a);
        vector<int>dp(target.size()+1,-1);
        int ans= solve(0,target,root,dp);
        if(ans==1e6)return -1;
        return ans;
    }
};