class Solution {
public:
    int mod=1e9+7;
    vector<vector<vector<int>>> dp;
    int dfs(vector<vector<int>>& grid, int k,int i,int j,int sum){
        int n=grid.size() ,m=grid[0].size();
        if(i>=n || j>=m){
            return 0;
        }
        
        sum=(sum+grid[i][j])%k;
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return (sum%k==0);
        }
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        long long way=0;
        way+=dfs(grid,k,i+1,j,sum);
        way=way%mod;
        way+=dfs(grid,k,i,j+1,sum);
        way=way%mod;
        return dp[i][j][sum]=way;

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int count=0;
        int n = grid.size(), m = grid[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));
        
        return dfs(grid,k,0,0,0);
    }
};