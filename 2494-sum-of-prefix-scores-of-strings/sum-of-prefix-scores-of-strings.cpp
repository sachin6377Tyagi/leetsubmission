struct Trie{
    Trie* child[26];
    int cnt=0;
    bool isWord=false;
    //for(int i=0;i<26;++i)child[i]=nullptr;
};

class Solution {
public:
   void insert(string &a,Trie* root){
    Trie* curr=root;
    for(int i=0;i<a.size();++i){
        int x=a[i]-'a';
        if(curr->child[x]==nullptr){
            Trie* node=new Trie();
            curr->child[x]=node;
        }
        curr=curr->child[x];
        curr->cnt++;
    }
    curr->isWord=true;
   }

   int solve(string &a,Trie* root){
    Trie *curr=root;
    int ans=0;
    for(int i=0;i<a.size();++i){
        int x=a[i]-'a';
        curr=curr->child[x];
        ans+=curr->cnt;
    }
    return ans;
   }
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root=new Trie();
        for(auto a:words){
            insert(a,root);
        }
        vector<int>ans;
        for(auto a:words){
            int num=solve(a,root);
            ans.push_back(num);
        }
        return ans;
    }
};