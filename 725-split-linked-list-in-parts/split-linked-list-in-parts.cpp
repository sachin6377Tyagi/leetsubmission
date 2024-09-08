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
   int count(ListNode* head){
       int cnt=0;
       while(head!=NULL){
           cnt++;
           head=head->next;
       }
       return cnt;
   }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>vec;
        int num=count(head);
        int rem=num%k;
        int div=num/k;

        ListNode* curr=head;
        int d=k;
        int rm=k-rem;
        while(rem--){
            int cnt=0;
            ListNode* ans=curr;
            while(cnt<div&&curr!=NULL){
               curr=curr->next;
               cnt++;
            }
            if(curr!=NULL){
                ListNode* next=curr->next;
                 curr->next=NULL;
                 vec.push_back(ans);
                curr=next;
                d--;
            }
        }

        while(rm--){
            int cnt=0;
            ListNode* ans=curr;
            while(cnt<(div-1)&&curr!=NULL){
                curr=curr->next;
                cnt++;
            }
            if(curr!=NULL){
                ListNode* next=curr->next;
                 curr->next=NULL;
                 vec.push_back(ans);
                curr=next;
                d--;
            }
        }

        while(d--){
            vec.push_back(NULL);
        }
        return vec;
        
    }
};