class Solution {
public:
    void dfs(vector<vector<int>>& matrix,int i,int j,int m,int n,int& count){
        
        for(int k=i+1;k<m && matrix[k][j]!=1 && matrix[k][j]!=2 ;k++){
            if(matrix[k][j]==0) count++;
            matrix[k][j]=-1;
        }

        for(int k=i-1;k>=0 && matrix[k][j]!=1 && matrix[k][j]!=2 ;k--){
            if(matrix[k][j]==0) count++;
            matrix[k][j]=-1;
        }
        for(int k=j-1;k>=0 && matrix[i][k]!=1 && matrix[i][k]!=2 ;k--){
            if(matrix[i][k]==0) count++;
            matrix[i][k]=-1;
        }
        for(int k=j+1;k<n && matrix[i][k]!=1 && matrix[i][k]!=2 ;k++){
            if(matrix[i][k]==0) count++;
            matrix[i][k]=-1;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> matrix(m,vector<int>(n,0));
        for(auto mt:guards){
            matrix[mt[0]][mt[1]]=1;
        }
        for(auto m:walls){
            matrix[m[0]][m[1]]=2;
        }
        int count=0;
        for(auto g:guards){
            dfs(matrix,g[0],g[1],m,n,count);
            // matrix[g[0]][g[1]]=1;
        }
        int ans=(m*n)-walls.size()-guards.size()-count;
        return ans;

    }
};