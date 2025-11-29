/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traversal(priority_queue<int>& heap,TreeNode* root, int k){
        if(root==NULL) return ;
        heap.push(root->val);
        if(heap.size()>k) heap.pop();
        traversal(heap,root->left,k);
        traversal(heap,root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> heap;
        traversal(heap,root,k);
        return heap.top();
    }
};