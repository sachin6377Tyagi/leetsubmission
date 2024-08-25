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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>st;
        TreeNode* node=root;
        while(!st.empty() || node){
            if(node){
                st.push(node);
                node=node->left;
            }
            else{
                TreeNode* temp=st.top();
                if(temp->right)node=temp->right;
                else{
                    ans.push_back(temp->val);
                    st.pop();
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        ans.push_back(temp->val);
                        st.pop();
                    }
                }
            }
        }
        return ans;
    }
};