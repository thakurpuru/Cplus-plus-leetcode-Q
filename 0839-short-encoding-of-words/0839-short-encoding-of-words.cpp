class TrieNode{
    public:
    TrieNode *child[26];
    string word;
    TrieNode(){
        word="";
        for(int i=0;i<26;i++){
            this->child[i]=NULL;
        }
    }
};
class Solution {
public:
    TrieNode *root=new TrieNode();
    void insert(string word){
        TrieNode *curr=root;
       
        for(int i=word.size()-1;i>=0;i--){
            int idx=word[i]-'a';
            if(curr->child[idx]==NULL){
                curr->child[idx]=new TrieNode();
                
            }
            curr=curr->child[idx];
        }
        curr->word=word;
    }
    void dfs(TrieNode *node,string &ans){
        bool leaf=true;
        for(int i=0;i<26;i++){
            if(node->child[i]!=NULL){
                leaf=false;
                dfs(node->child[i],ans);
                
            }
        }
        if(leaf && node->word!=""){
            ans+=node->word+'#';
           
        }
    }
    int minimumLengthEncoding(vector<string>& words) {
        for(auto w:words){
            insert(w);
        }
        string ans="";
        dfs(root,ans);
        cout<<ans;
        return ans.size();

    }
};