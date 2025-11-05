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
        int count=0;
        while(temp!=NULL ){
            count++;
            temp=temp->next;
        }
        if(k==0) return head;
        k=k%count;
        if(k==0) return head;
        int req=count-k;
        temp=head;
        for(int i=1;i<req;i++){
            temp=temp->next;
        }
        ListNode* temp1=temp->next;
        ListNode* newhead=temp1;
        temp->next=NULL;
        while(temp1!=NULL && temp1->next!=NULL){
            temp1=temp1->next;
        }
        if(temp1!=NULL)
        temp1->next=head;
        return newhead;
        
    }
};