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
    TreeNode* construct(vector<int>& inorder,vector<int>& pos,int i,int j,int& k,unordered_map<int,int>& mp){
         if(i>j) return NULL;
    
        int value=pos[k--];
        int mid=mp[value];
        
        TreeNode* root=new TreeNode(value);
        root->right=construct(inorder,pos,mid+1,j,k,mp);
        root->left=construct(inorder,pos,i,mid-1,k,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int k=postorder.size()-1;
        TreeNode* root=construct(inorder,postorder,0,inorder.size()-1,k,mp);
        return root;
    }
};