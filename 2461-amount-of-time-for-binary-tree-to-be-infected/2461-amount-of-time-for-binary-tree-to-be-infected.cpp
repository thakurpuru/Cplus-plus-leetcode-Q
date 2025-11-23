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
    unordered_map<int,TreeNode*>parentMap;
    void buildMap(TreeNode* root) {
        if (!root) return;
        
        queue<TreeNode*> q;
        q.push(root);
        parentMap[root->val] = nullptr;
        
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            if (current->left) {
                parentMap[current->left->val] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentMap[current->right->val] = current;
                q.push(current->right);
            }
        }
    }
    TreeNode* node;
    void Traversal(TreeNode* root,int start){
        if(!root) return ;
        if(root->val==start){
            node=root;
            return;
        }
        Traversal(root->left,start);
        Traversal(root->right,start);
    }

    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*>q;
        unordered_set<TreeNode*>st;
        Traversal(root,start);
        buildMap(root);
        q.push(node);
        st.insert(node);
        int count=0;
        while(!q.empty()){
            int size=q.size();
            int check=0;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !st.count(temp->left)){
                    q.push(temp->left);
                    st.insert(temp->left);
                    check=1;
                }
                if(temp->right && !st.count(temp->right)){
                    q.push(temp->right);
                    st.insert(temp->right);
                    check=1;
                }
                TreeNode* parent=parentMap[temp->val];
                if(parent && !st.count(parent)){
                    q.push(parent);
                    st.insert(parent);
                    check=1;
                }

            }
            if(check==1)count++;

        }
        return count;
    }
};