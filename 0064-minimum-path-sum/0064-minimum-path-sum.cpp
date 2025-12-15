class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=1e9;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        function<int(int,int)> dfs=[&](int i,int j){
            if(i>=n || j>=m) return INT_MAX;

            if(dp[i][j]!=-1) return dp[i][j];
            
            if(i==n-1 && j==m-1) return grid[i][j];
            int down=dfs(i+1,j);
            int right=dfs(i,j+1);

            
            return dp[i][j]=grid[i][j]+min(down,right);

        };
       
        return dfs(0,0);
    }
};