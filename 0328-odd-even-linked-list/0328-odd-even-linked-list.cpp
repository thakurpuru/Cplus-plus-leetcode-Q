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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp=head;
        if (temp==NULL) return NULL;
        if(temp->next==NULL) return head;
        ListNode* pre=temp->next;
        ListNode* tail=pre;
    while(temp!=nullptr && temp->next!=nullptr){
        temp->next=pre->next;
        if(temp->next!=NULL)
        pre->next=temp->next->next;
        temp=temp->next;
        pre=pre->next;
    }
    if(temp==NULL){
        pre=head;
        while(pre->next!=NULL){
            pre=pre->next;
        }
        pre->next=tail;
        return head;
    }
    temp->next=tail;
    return head;


        
        
    }
};