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
class Solution {
public:
    TrieNode *root=new TrieNode();
    void insert(string word){
        TrieNode* curr=root;
        for(char c:word){
            int idx=c-'a';
            if(curr->child[idx]==NULL){
                curr->child[idx]=new TrieNode();
            }
            curr=curr->child[idx];
        }
        curr->eof=true;
    }
    // bool search(string word){
    //     TrieNode* curr=root;
    //     for(char c:word){
    //         int idx=c-'a';
    //         if(curr->)
    //     }
    // }
    vector<string> res;
    void dfs(vector<vector<char>>& board,int i,int j,string word,TrieNode *node){
       if(node->eof){
            res.push_back(word);
            node->eof=false;
       }
        

        int dx[4]={0,1,-1,0};
        int dy[4]={1,0,0,-1};
        char temp=board[i][j];
        board[i][j]='#';
        
        for(int k=0;k<4;k++){
            int x1=i+dx[k];
            int y1=j+dy[k]; 
            if(x1>=0 && x1<board.size() && y1>=0 && y1<board[0].size() && board[x1][y1]!='#'){
                int idx=board[x1][y1]-'a';
                if(node->child[idx]!=NULL){
                    dfs(board,x1,y1,word+board[x1][y1],node->child[idx]);
                }
                
            }   
            
            
        }
        board[i][j]=temp;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        int m=board.size(),n=board[0].size();
        for(auto w:words){
            insert(w);
        }
        string w="";
        TrieNode *curr=root; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int idx=board[i][j]-'a';
                if(curr->child[idx]!=NULL){
                    dfs(board,i,j,w+board[i][j],curr->child[idx]);
                }
                    
            }
        }
        
        return res;
    }
};