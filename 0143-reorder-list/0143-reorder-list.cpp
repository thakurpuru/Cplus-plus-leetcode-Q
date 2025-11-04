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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        
       vector<ListNode*> vec;
        while(fast!=NULL && fast->next!=NULL ){
            slow=slow->next;
            fast=fast->next->next;
            
        }
        fast=slow;
        while(fast!=NULL){
            vec.push_back(fast);
            fast=fast->next;
        }
        ListNode* curr=head;
        ListNode* curr_next=head->next;
        for(int i=vec.size()-1;i>0 && curr!=slow;i--){
            ListNode* temp=vec[i-1];
            if(temp->next!=NULL){

                curr->next=temp->next;
                
                temp->next->next=curr_next;
                temp->next=NULL;
            }
            curr=curr_next;
            curr_next=curr_next->next;
        }
        // while(curr!=slow){
        //     ListNode* temp=slow;
        //     if(temp->next!=NULL){

        //         while(temp->next!=NULL && temp->next->next!=NULL){
        //             temp=temp->next;
        //         }
        //         curr->next=temp->next;
                
        //         temp->next->next=curr_next;
        //         temp->next=NULL;
        //     }
        //     curr=curr_next;
        //     curr_next=curr_next->next;
            

        // }


    }
};