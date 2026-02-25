class Solution {
public:
    bool dfs(vector<vector<char>>& board,int i,int j,int idx,string word){
        if(idx==word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[idx]) return false;

        int dx[4]={0,1,-1,0};
        int dy[4]={1,0,0,-1};
        char temp=board[i][j];
        board[i][j]='#';
        bool found=false;
        for(int k=0;k<4;k++){
            int x1=i+dx[k];
            int y1=j+dy[k];    
            found=found || dfs(board,x1,y1,idx+1,word);
            
        }
        board[i][j]=temp;
        return found;

    }
    bool exist(vector<vector<char>>& board, string word) {
        queue<pair<int,int>> q;
        int m=board.size(),n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,i,j,0,word)) return true;
                    
                }
            }
        }
       
        return false;

    }
};