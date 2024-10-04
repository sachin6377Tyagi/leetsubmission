class Solution {
public:
   struct node{
    node* left=NULL;
    node* right=NULL;
   };

   void insert(node* root,int num){
    node* curr=root;
    for(int i=31;i>=0;i--){
        if(num&(1<<i)){
            if(!curr->right){
                node* newNode=new node();
                curr->right=newNode;
            }
            curr=curr->right;
        }
        else{
            if(!curr->left){
                node* newNode=new node();
                curr->left=newNode;
            }
            curr=curr->left;
        }
    }
   }

   int solve(node* root,int num){
    node* curr=root;
    int ans=0;
    for(int i=31;i>=0;i--){
        if(num&(1<<i)){
            if(curr->left){
                ans+=pow(2,i);
                curr=curr->left;
            }
            else curr=curr->right;
        }
        else{
            if(curr->right){
                ans+=pow(2,i);
                curr=curr->right;
            }
            else curr=curr->left;
        }
    }
    return ans;
   }
    int findMaximumXOR(vector<int>& nums) {
        node* root=new node();
        int n=nums.size();
        for(int i=0;i<n;++i)insert(root,nums[i]);
        int ans=0;
        for(int i=0;i<n;++i){
            ans=max(ans,solve(root,nums[i]));
        }
        return ans;
    }
};