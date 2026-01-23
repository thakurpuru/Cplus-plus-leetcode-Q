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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node1=NULL;
        TreeNode* nodekey=NULL;
        TreeNode* parentNode=NULL;
        function<void(TreeNode*,TreeNode*)> search=[&](TreeNode* node,TreeNode* par){
            if(!node) return;
            if(node->val==key){
                nodekey=node;
                parentNode=par;
                return;
            }
            search(node->left,node);
            search(node->right,node);
        };
        search(root,node1);
        if(nodekey==NULL) return root;
        if(!nodekey->left){
            if(!parentNode) return nodekey->right;
            if(parentNode->left==nodekey) parentNode->left=nodekey->right;
            else parentNode->right=nodekey->right;
            return root;
        }
        if(!nodekey->right){
            if(!parentNode) return nodekey->left;
            if(parentNode->left==nodekey)parentNode->left=nodekey->left;
            else parentNode->right=nodekey->left;
            return root;
        }

       TreeNode* deep=nodekey->right;
       TreeNode* parentDeep=nodekey;
        while(deep->left){
            parentDeep=deep;
            deep=deep->left;
        }
        nodekey->val=deep->val;
        if(parentDeep->left == deep) parentDeep->left = deep->right;
        else parentDeep->right = deep->right;

        
        return root;
    }
};