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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int siz_e=0;
        while(temp!=nullptr){
            siz_e++;
            temp=temp->next;
        } 
        temp=head;
        if(siz_e==n){
            ListNode* newhead=temp->next;
            delete head;
            return newhead;
        }
        int i=siz_e-n;
        for(int j=1;j<i;j++){
            temp=temp->next;
        }
        ListNode* delnode=temp->next;
        temp->next=delnode->next;
        delete delnode;
        return head;

    }
};