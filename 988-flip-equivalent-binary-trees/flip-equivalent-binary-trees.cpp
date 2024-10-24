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
//    bool solve(TreeNode* root1, TreeNode* root2){
//     if()
//    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL)return true;
        if(root1==NULL || root2==NULL)return false;
        if(root1->val !=root2->val)return false;
        bool flip=0;
        if((!root1->left && root2->left) && (root1->right && !root2->right)){
            if(root1->right->val==root2->left->val)flip=1;
           // else return false;
        }
        else if((root1->left && !root2->left) && (!root1->right && root2->right)){
            if(root2->right->val==root1->left->val)flip=1;
           // else return false;
        }
        else if((root1->left && root2->left) && (root1->right && root2->right)){
            if(root1->right->val==root2->left->val && root2->right->val==root1->left->val)flip=1;
            //else return false;
        }
        if(flip)return flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);
        else return flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
    }
};