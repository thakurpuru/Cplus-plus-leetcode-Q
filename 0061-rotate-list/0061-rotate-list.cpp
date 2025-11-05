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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        if(temp==NULL) return temp;
        if(temp->next==NULL) return temp;
        ListNode* slow=head,*fast=head;
        int n=0;
        while(fast!=NULL){
            fast=fast->next;
            n++;
        }
        if(k==0) return head;
        k=k%n;
        if(k==0) return head;
        int count=0;
        while(count!= k){
            temp=temp->next;
            count++;
        }
        
        while(temp->next!=NULL){
            temp=temp->next;
            slow=slow->next;
        }
        ListNode* newhead=slow->next;
        slow->next=NULL;
        temp->next=head;
        return newhead;
        
    }
};