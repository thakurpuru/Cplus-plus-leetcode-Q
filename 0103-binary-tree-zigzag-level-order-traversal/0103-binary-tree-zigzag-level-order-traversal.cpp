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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
        int leve=0;
        deque<TreeNode*> q;
        int level=0;
        q.push_back(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> vec;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop_front();
                if(node){
                    vec.push_back(node->val);
                    if(node->left) q.push_back(node->left);
                    if(node->right) q.push_back(node->right);

                }
            }
            if(level%2!=0)reverse(vec.begin(),vec.end());
            level++;
            res.push_back(vec);
        }
        return res;
    }
};