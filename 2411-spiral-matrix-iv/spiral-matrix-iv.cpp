/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int left=0,right=n-1,top=0,bottom=m-1;
        while(head){
            int i=left;
            while(head && i<=right){
                ans[top][i]=head->val;
                i++;
                head=head->next;
            }
            top++;
            i=top;
            while(head && i<=bottom){
                ans[i][right]=head->val;
                i++;
                head=head->next;
            }
            right--;
            i=right;
            while(head && i>=left){
                ans[bottom][i]=head->val;
                i--;
                head=head->next;
            }
            bottom--;
            i=bottom;
            while(head && i>=top){
                ans[i][left]=head->val;
                i--;
                head=head->next;
            }
            left++;
        }
        return ans;
    }
};