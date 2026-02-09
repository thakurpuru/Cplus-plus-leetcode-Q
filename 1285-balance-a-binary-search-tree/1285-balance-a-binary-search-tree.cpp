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
    vector<int>vec;
    void sortedTree(TreeNode* node){
        if(node==NULL) return;
        sortedTree(node->left);
        vec.push_back(node->val);
        sortedTree(node->right);
    }
    TreeNode* newBST(int st,int end){
        if(st>end) return NULL;

        int mid=st+(end-st)/2;
        TreeNode* node=new TreeNode(vec[mid]);
        node->left=newBST(st,mid-1);
        node->right=newBST(mid+1,end);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        sortedTree(root);
        int n=vec.size();
        return newBST(0,n-1);
    }
};