struct node{
    int val=0;
    node* left=NULL;
    node* right=NULL;
};
class Solution {
public:
   void insert(node* root,int num){
    node* curr=root;
    for(int i=20;i>=0;i--){
        if(num&(1<<i)){
            if(!curr->right){
                node* newNode=new node();
                curr->right=newNode;
            }
            curr=curr->right;
            curr->val++;
        }
        else{
            if(!curr->left){
                node* newNode=new node();
                curr->left=newNode;
            }
            curr=curr->left;
            curr->val++;
        }
    }
   }
   int solve(node* root,int num){
    node* curr=root;
    int ans=0;
    for(int i=20;i>=0;i--){
        if(num&(1<<i)){
            if(curr->left && curr->left->val>0){
                ans+=(1<<i);
                curr=curr->left;
            }
            else if(curr->right && curr->right->val>0)curr=curr->right;
            else return 0;
        }
        else{
            if(curr->right && curr->right->val>0){
                ans+=(1<<i);
                curr=curr->right;
            }
            else if(curr->left && curr->left->val>0) curr=curr->left;
            else return 0;
        }
    }
    return ans;
   }
   void deleteNode(node* root,int num){
    node* curr=root;
    for(int i=20;i>=0;i--){
        if(num&(1<<i)){
            curr=curr->right;
        }
        else curr=curr->left;
        curr->val--;
    }
   }
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0,j=0;
         node* root=new node();
        for(int i=0;i<n;++i){
            if(i>0)deleteNode(root,nums[i-1]);
            while(j<n && nums[j]<=2*nums[i]){
                insert(root,nums[j++]);
            }
            ans=max(ans,solve(root,nums[i]));
        }
        return ans;
    }
};