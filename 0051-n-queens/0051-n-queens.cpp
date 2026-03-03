class Solution {
public:
    bool issafe(int r,int c,vector<string> &board,int n){
        for(int i=0;i<r;i++){
            if(board[i][c]=='Q') return false;
        }
        for(int j=0;j<c;j++){
            if(board[r][j]=='Q') return false;
        }
        int i=1;
        while(r-i>=0 && c-i>=0){
            if(board[r-i][c-i]=='Q') return false;
            i++;
        }
        i=1;
        while(r-i>=0 && c+i<n){
            if(board[r-i][c+i]=='Q') return false;
            i++;
        }
        return true;

    }
    vector<vector<string>> res;
    void solve(vector<string>& board,int n,int row){
        if(row==n){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(issafe(row,i,board,n)){
                board[row][i]='Q';
                solve(board,n,row+1);
                board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s1="";
        for(int i=0;i<n;i++){
            s1+='.';
        }
        for(int i=0;i<n;i++){
            board[i]=s1;
        }
        solve(board,n,0);
        return res;
    }
};