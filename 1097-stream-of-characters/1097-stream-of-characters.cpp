class TrieNode{
    public:
    TrieNode *child[26];
    bool eof;
    TrieNode(){
        eof=false;
        for(int i=0;i<26;i++){
            this->child[i]=NULL;
        }
    }
};
class StreamChecker {
public:
    TrieNode *root=new TrieNode();
     string currWord;
    void insert(string word){
        TrieNode *curr=root;
        for(int i=word.size()-1;i>=0;i--){
            int idx=word[i]-'a';
            if(curr->child[idx]==NULL){
                
                curr->child[idx]=new TrieNode();   
            }
            curr=curr->child[idx];
        }
        curr->eof=true;
    }
    StreamChecker(vector<string>& words) {
        currWord="";
        for(auto w:words){
            insert(w);
        }
    }
    
    bool query(char letter) {

        this->currWord+=letter;
        TrieNode *curr=root;
        for(int i=this->currWord.size()-1;i>=0;i--){
            int idx=this->currWord[i]-'a';
            if(curr->child[idx]==NULL) return false;
            curr=curr->child[idx];
            if(curr->eof) return true;
        }
        return false;
        
    }
};


/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */