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
    TreeNode* construct(auto i,auto j,vector<int>& nums){
        if(i>=j) return NULL;
        auto it=max_element(i,j);
        TreeNode* root=new TreeNode(*it);

        root->left=construct(i,it,nums);
        root->right=construct(it+1,j,nums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root=construct(nums.begin(),nums.end(),nums);
        return root;
        
    }
};