class Solution {
public:
    vector<vector<int>>dp;
    const int mod=1e9+7;
    int dfs(vector<vector<int>>& grid,int i,int j){
        // if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        long long maxpath=1;
        if(i>0 && grid[i-1][j]>grid[i][j]){
            maxpath=(maxpath+dfs(grid,i-1,j))%mod;
        }
        if(i<grid.size()-1 && grid[i+1][j]>grid[i][j]){
            maxpath=(maxpath+dfs(grid,i+1,j))%mod;
        }
        if(j<grid[0].size()-1 && grid[i][j+1]>grid[i][j]){
            maxpath=(maxpath+dfs(grid,i,j+1))%mod;
        }
        if(j>0 && grid[i][j-1]>grid[i][j]){
            maxpath=(maxpath+dfs(grid,i,j-1))%mod;
        }
        dp[i][j]=maxpath%mod;
        return maxpath;
    }
    int countPaths(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size(),m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count=(count+dfs(grid,i,j))%mod;
            }
        }
        return count;
    }
};