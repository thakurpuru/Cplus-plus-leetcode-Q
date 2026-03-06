class WordDictionary {
public:
    WordDictionary *child[26];
    bool eof;
    WordDictionary() {
        eof=false;
        for(int i=0;i<26;i++){
            this->child[i]=NULL;
        }
    }
    
    void addWord(string word) {
        WordDictionary *curr=this;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';;
            if(curr->child[idx]==NULL){
                curr->child[idx]=new WordDictionary();
            }
            curr=curr->child[idx];
        }
        curr->eof=true;
    }
    bool dfs(string word,int i,WordDictionary *node){
        if(i==word.size()) return node->eof;

        if(word[i]=='.'){
            for(int j=0;j<26;j++){
                if(node->child[j]!=NULL && dfs(word,i+1,node->child[j]))
                return true;
            }
            return false;
        }
        int idx=word[i]-'a';
        if(node->child[idx]==NULL) return false;
        return dfs(word,i+1,node->child[idx]);

    }
    bool search(string word) {
        return dfs(word,0,this);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */