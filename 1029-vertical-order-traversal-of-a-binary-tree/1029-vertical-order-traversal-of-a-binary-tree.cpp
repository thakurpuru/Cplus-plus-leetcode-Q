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
    vector<vector<int>> ans;
    void traversal(TreeNode* root){
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,vector<pair<int,int>>> mp;
        int level=0;
        q.push({root,{0,0}});
        while(!q.empty()){
            int size=q.size();
            level++;
            for(int i=0;i<size;i++){
                auto [node,rest]=q.front();
                auto [x,y]=rest;
                q.pop();
                 mp[y].push_back({x,node->val});
                if(node->left!=NULL){
                    
                    q.push({node->left,{level,y-1}});
                }
                if(node->right!=NULL){
                    q.push({node->right,{level,y+1}});
                }

            }
        }
        for(auto m:mp){
            cout<<m.first<<"->";
            auto &vec=m.second;
            sort(vec.begin(),vec.end(),[](auto &a,auto &b){
                if(a.first==b.first) return a.second<b.second ;
                return a.first<b.first;
            });
            vector<int> col;
            for(auto i:vec) col.push_back(i.second);
            ans.push_back(col);
        }

        

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traversal(root);
        return ans;
    }
};