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
    
    // void traversal(TreeNode* r){
    //     if(!r) return;
    //     ans.push_back(r->val);
    //     traversal(r->left);
    //     traversal(r->right);
    // }
    TreeNode* searchBST(TreeNode* root, int val) {

        function<TreeNode*(TreeNode*)> search=[&](TreeNode* r)-> TreeNode*{
            if(r==NULL) return NULL;
            if(r->val==val) 
                return r;
            else if(r->val>val) 
                return search(r->left);
            else return search(r->right);

            return NULL;

        };
        
        return search(root);
        
    }
};