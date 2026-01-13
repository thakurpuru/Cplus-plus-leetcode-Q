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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        function<void(TreeNode*)> insert=[&](TreeNode* r){
            if(r==NULL) return;

            if(val<r->val){
                if(r->left!=NULL){
                    insert(r->left);
                }else{
                  r->left=new TreeNode(val); 
                  return; 
                }
            }else {
                if(r->right!=NULL){
                    insert(r->right);
                }else{
                  r->right=new TreeNode(val);  
                  return;
                }
            }
        };
        insert(root);
        return root;
    }
};