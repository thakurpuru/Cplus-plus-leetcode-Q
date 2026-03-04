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
    bool solve(vector<vector<char>>& board,int id,vector<unordered_set<char>>& row_set,vector<unordered_set<char>>& col_set,vector<unordered_set<char>>& box_set){
        if(id==empty.size()) return true;
        auto [r,c]=empty[id];
        int idx=(r/3)*3+(c/3);
        for(int i=1;i<=9;i++){
            char ch=i+'0';
            if(!row_set[r].count(ch) && !col_set[c].count(ch) && !box_set[idx].count(ch)){
                row_set[r].insert(ch);
                col_set[c].insert(ch);
                box_set[idx].insert(ch);
                board[r][c]=ch;
                if(solve(board,id+1,row_set,col_set,box_set)) return true;
                board[r][c]='.';
                row_set[r].erase(ch);
                col_set[c].erase(ch);
                box_set[idx].erase(ch);

            }
            
        }
        return false;

        
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row_set(9),col_set(9),box_set(9);

        for(int k=0;k<9;k++){
            for(int l=0;l<9;l++){
                if(board[k][l]!='.'){
                    char ch=board[k][l];
                    row_set[k].insert(ch);
                    col_set[l].insert(ch);
                    int idx=(k/3)*3+(l/3);
                    box_set[idx].insert(ch);
                }else{
                    empty.push_back({k,l});
                }
            }
        }
        solve(board,0,row_set,col_set,box_set);
    }
};