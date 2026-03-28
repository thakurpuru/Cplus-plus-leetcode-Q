class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& grid,int i,int j,int X_or){
        int m=grid.size(),n=grid[0].size();
        if(i>=m || j>=n) return INT_MAX;
        X_or^=grid[i][j];
        if(i==m-1 && j==n-1) return X_or;
        if(dp[i][j][X_or]!=-1) return dp[i][j][X_or];
        
        int c1=solve(grid,i,j+1,X_or);
        int c2=solve(grid,i+1,j,X_or);
        return dp[i][j][X_or]=min(c1,c2);
        
    }
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(1024,-1)));
        return solve(grid,0,0,0);
    }
};