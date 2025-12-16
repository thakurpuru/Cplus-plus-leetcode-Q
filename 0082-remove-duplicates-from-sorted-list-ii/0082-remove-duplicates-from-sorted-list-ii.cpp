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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        if(head==NULL) return head;
        ListNode* next=head->next;
        if(next==NULL) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        while(curr!=NULL){
            if(curr->next && curr->val==curr->next->val){
                int duplVal=curr->val;
                while(curr && curr->val==duplVal){
                    curr=curr->next;
                }
                prev->next=curr;
                
            }else{
                prev=curr;
                curr=curr->next;

            }
        } 
        return dummy->next;  
    }
};