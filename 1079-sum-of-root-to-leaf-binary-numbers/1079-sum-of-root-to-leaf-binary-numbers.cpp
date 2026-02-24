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
    vector<string> vec;
    void preorder(TreeNode* node,string s){
        if(!node){
            return;
        }
        s=s+to_string(node->val);
        if(!node->left && !node->right){
            vec.push_back(s);
            return ;
        }
        preorder(node->left,s);
        preorder(node->right,s);
    }
    int sumRootToLeaf(TreeNode* root) {
        preorder(root,"");
        int ans=0;
        for(auto s:vec){
            int n=s.size(),i=n-1;
            while(i>=0){
                int a=s[i]-'0';
                ans+=(a*(1<<(n-1-i)));
                i--;
            }
        }
        return ans;
    }
};