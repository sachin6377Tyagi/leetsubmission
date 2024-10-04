static bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
};
struct node{
    node* left=NULL;
    node* right=NULL;
};
class Solution {
public:
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>>vec;
        int j=0;
        for(auto q:queries){
            vector<int>temp={q[0],q[1],j};
            j++;
            vec.push_back(temp);
        }
       sort(vec.begin(),vec.end(),cmp); 
       sort(nums.begin(),nums.end());
       vector<int>ans(vec.size());
       node* root=new node();
       int i=0;
       //for(int i=0;i<nums.size();++i)insert(root,nums[i]);
       for(auto q:vec){
        while(i<nums.size() && nums[i]<=q[1])insert(root,nums[i++]);
        //cout<<q[0]<<" "<<q[1]<<endl;
        if(i==0){
            ans[q[2]]=-1;
            continue;
        }
        int a=solve(root,q[0]);
        ans[q[2]]=a;
       }
       return ans;
    }
};