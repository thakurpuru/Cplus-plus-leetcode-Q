class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<vector<int>>& mat){
        int m=mat.size();
        int n=mat[0].size();
        if(i==m-1 && j==n-1) return mat[i][j]<=0?-mat[i][j]+1:1;
        if(i>=m || i<0 || j>=n || j<0){
            return 1e9;
        }
        if(dp[i][j]!=1e9) return dp[i][j];
        int val=min(solve(i+1,j,mat),solve(i,j+1,mat))-mat[i][j];
        dp[i][j]=val<=0?1:val;
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        dp.assign(m,vector<int>(n,1e9));
        return solve(0,0,dungeon);
    }
};