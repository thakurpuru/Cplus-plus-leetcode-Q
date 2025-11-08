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
        ListNode* prev=head;
        if(prev==NULL) return head;
        if(prev->next==NULL) return prev;
        ListNode* next=head->next;
        while(next!=NULL){
            if(prev!=NULL && prev->val==next->val){
                prev->next=next->next;
                next->next=NULL;
                
                if(prev!=NULL)
                next=prev->next;
            }else{
                if(prev!=NULL)
                prev=prev->next;
                next=next->next;
            }
        }
        return head;

    }
};