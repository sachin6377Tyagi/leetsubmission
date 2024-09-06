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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* curr=head;
        ListNode* prv=NULL;
        set<int>st;
        for(auto num:nums)st.insert(num);
       while(curr){
        if(st.find(curr->val)!=st.end()){
            ListNode* temp=curr->next;
            if(prv){
                prv->next=temp;
            }
            else{
                head=temp;
            }
            curr=temp;
        }
        else{
            prv=curr;
            curr=curr->next;
        }
       }
       return head;
    }
};