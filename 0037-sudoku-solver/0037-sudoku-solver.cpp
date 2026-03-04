class Solution {
public:
    bool issafe(vector<vector<char>>& board,int i,int j,char num){
        int row=i/3*3;
        int col=j/3*3;
        for(int k=row;k<row+3;k++){
            for(int l=col;l<col+3;l++){
                if(board[k][l]==num) return false;
            }
        }
        for(int k=0;k<9;k++){
            if(board[k][j]==num) return false;
        }
        for(int k=0;k<9;k++){
            if(board[i][k]==num) return false;
        }
        return true;
    }
    vector<pair<int,int>> empty;
    bool solve(vector<vector<char>>& board,int id){
        if(id==empty.size()) return true;
        auto [r,c]=empty[id];
        int idx=(r/3)*3+(c/3);
        for(int i=1;i<=9;i++){
            char ch=i+'0';
            if(issafe(board,r,c,ch)){
                board[r][c]=ch;
                if(solve(board,id+1)) return true;
                board[r][c]='.';
                

            }
            
        }
        return false;

        
    }
    void solveSudoku(vector<vector<char>>& board) {
       

        for(int k=0;k<9;k++){
            for(int l=0;l<9;l++){
                if(board[k][l]=='.'){
                    empty.push_back({k,l});
                }
            }
        }
        solve(board,0);
    }
};