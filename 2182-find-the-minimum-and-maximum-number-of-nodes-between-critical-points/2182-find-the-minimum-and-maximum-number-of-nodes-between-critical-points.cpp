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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> vec;

        ListNode* pre=head;
        ListNode* curr=head->next;
        int i=1;
        while(curr->next!=NULL){
            if(pre->val<curr->val && curr->val>curr->next->val){
                vec.push_back(i+1);
            }else if(pre->val>curr->val && curr->val<curr->next->val){
                vec.push_back(i+1);
            }
            i++;
            pre=curr;
            curr=curr->next;
        }
        if(vec.size()<=1) return {-1,-1};
        int k=INT_MAX;
        for(int i=1;i<vec.size();i++){
            k=min(k,vec[i]-vec[i-1]);
        }
        int j=vec.back()-vec[0];
        return {k,j};
    }
};