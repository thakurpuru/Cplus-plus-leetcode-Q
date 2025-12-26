class Solution {
public:
    int mod=2*1e9;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=0;
        function<int(int,int)> dfs=[&](int i,int j){
            if(i>=m || j>=n || obstacleGrid[i][j]==1) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            if(i==m-1 && j==n-1){
                return 1;
            }
            int path=0;
            if(i<m-1 && obstacleGrid[i+1][j]==0){
                path+=dfs(i+1,j);
            }
            if(j<n-1 && obstacleGrid[i][j+1]==0){
                path+=dfs(i,j+1);
            }
            return dp[i][j]=path;
        };
        
        return dfs(0,0);
    }
};