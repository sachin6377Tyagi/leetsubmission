/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   int n=1;
   void countNodes(TreeNode* root){
    if(root->left){
        n++;
        countNodes(root->left);
    }
    if(root->right){
        n++;
        countNodes(root->right);
    }
   }

   void indexing(int &ind,TreeNode* root,vector<int>&st,vector<int>&end){
    st[root->val]=ind;
    if(root->left){
        ind++;
        indexing(ind,root->left,st,end);
    }
    if(root->right){
        //st[root->val]=ind;
        ind++;
        indexing(ind,root->right,st,end);
    }

    end[root->val]=ind;
   }

   void findMaxi(TreeNode* root,int d,vector<int>&maxi,vector<int>&st){
    maxi[st[root->val]]=d;
    if(root->left)findMaxi(root->left,d+1,maxi,st);
    if(root->right)findMaxi(root->right,d+1,maxi,st);
   }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        countNodes(root);
        vector<int>ans;
        vector<int>st(n+1,0);
        vector<int>end(n+1,0);
        int ind=1;
        indexing(ind,root,st,end);
        vector<int>maxi(n+1,0);
        findMaxi(root,0,maxi,st);
        //for(int i=1;i<=n;++i)cout<<st[i]<<" "<<end[i]<<endl;
        vector<int>pre(n+2,0);
        vector<int>suff(n+2,0);
        for(int i=1;i<=n;++i)pre[i]=max(pre[i-1],maxi[i]);
        for(int i=n;i>0;i--)suff[i]=max(suff[i+1],maxi[i]);
        for(int i=0;i<queries.size();++i){
            int q=queries[i];
            int l=st[q],r=end[q];
            ans.push_back(max(pre[l-1],suff[r+1]));
        }
        return ans;
    }
};