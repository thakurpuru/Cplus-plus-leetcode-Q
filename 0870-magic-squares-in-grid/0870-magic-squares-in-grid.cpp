class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(n<3 || m<3) return 0;
        // if(n==3 && m==3) return 0;

        function<bool(int,int)> check=[&](int i,int j){
            vector<bool> used(10,false);
            used[0]=true;
            int sum=grid[i][j]+grid[i+1][j]+grid[i-1][j];
            for (int r = i - 1; r <= i + 1; r++) {
                for (int c = j - 1; c <= j + 1; c++) {
                    int val = grid[r][c];
                    if (val < 1 || val > 9 || used[val])
                        return false;
                    used[val] = true;
                }
            }

            for(int r=i-1;r<=i+1;r++){
                int rowsum=0;
                for(int col=j-1;col<=j+1;col++){
                    int val=grid[r][col];
                    rowsum+=val;
                }
                if(rowsum!=sum) return false;
            }

            if(grid[i][j]+grid[i+1][j+1]+grid[i-1][j-1]!=sum) return false;
            if(grid[i][j]+grid[i-1][j+1]+grid[i+1][j-1]!=sum) return false;
            for(int col=j-1;col<=j+1;col++){
                int rowsum=0;
                for(int r=i-1;r<=i+1;r++){
                    rowsum+=grid[r][col];
                }
                if(rowsum!=sum) return false;
            }

            
            return true;

        };
        int count=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                
                if(grid[i][j]==5 && check(i,j)) count++;
            }
        }
        return count;
    }
};