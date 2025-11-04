/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        int count=0;
        if(head==NULL) return NULL;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow== fast){
                count=1;
                break;
            }
        }
        if(count==0) return NULL;
        slow=head;
        while(slow!=fast){
           slow=slow->next;
            fast=fast->next; 
        }
        return slow;
    }

};