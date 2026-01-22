/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        function<void(TreeNode*)> find=[&](TreeNode* temp){
            queue<TreeNode*> q;
            
            q.push(temp);
            while(!q.empty()){
                int size=q.size();
                
                for(int i=0;i<size;i++){
                    auto node=q.front();
                    q.pop();
                    
                    if(node->left){
                        mp[node->left]=node;
                        q.push(node->left);
                    }
                    if(node->right){
                        mp[node->right]=node;
                        q.push(node->right);
                    }

                }
            }
        };
        find(root);
        vector<int> ans;
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        vis.insert(target);
        int dist=0;
        q.push(target);
        while(!q.empty()){
            int size=q.size();
            if(k==dist) break;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis.count(node->left)){
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right && !vis.count(node->right)){
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if(mp[node] && !vis.count(mp[node])){
                    q.push(mp[node]);
                    vis.insert(mp[node]);
                }


            }
            dist++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

    }
};