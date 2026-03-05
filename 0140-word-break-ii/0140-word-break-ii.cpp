class TrieNode{
    public:
    TrieNode *children[26];
    bool eof;
    TrieNode(){
        eof=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class Solution {
public:
    TrieNode *root=new TrieNode();
    unordered_map<int,bool> memo;
    void insert(string word){
        TrieNode *curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(curr->children[idx]==NULL){
                TrieNode *newnode= new TrieNode();
                curr->children[idx]=newnode;
            }
            curr=curr->children[idx];
        }
        curr->eof=true;
    }
    bool search(string word){
        TrieNode *curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(curr->children[idx]==NULL) return false;
            curr=curr->children[idx];
        }
        return curr->eof;
    }
    void backtrack(string& s,int start,vector<string>& curr,vector<string>& result){
        if(memo.count(start)) return;
        int before = result.size(); 
        if(start==s.size()){
            string sentence="";
            for(auto& word:curr){
                if(sentence!="") sentence+=" ";
                sentence+=word;
            }
            result.push_back(sentence);
        }
        for(int i=start+1;i<=s.size();i++){
            string word=s.substr(start,i-start);
            if(search(word)){
                curr.push_back(word);
                backtrack(s,i,curr,result);
                curr.pop_back();
            }
        }
        if(before == result.size())     
        memo[start] = true;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        vector<string> curr;
        
        for(int i=0;i<wordDict.size();i++){
            insert(wordDict[i]);
        }
        
        backtrack(s,0,curr,result);
        return result;
    }
};