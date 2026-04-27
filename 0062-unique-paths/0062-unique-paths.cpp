class Solution {
public:
    vector<vector<int>> dp;
    int solve(int m,int n,int i,int j){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(i+1<m){
            ans+=solve(m,n,i+1,j);
        }
        if(j+1<n){
            ans+=solve(m,n,i,j+1);
        }
        return dp[i][j]=ans;
    }
    int uniquePaths(int m, int n) {
        dp.assign(m,vector<int>(n,-1));
        return solve(m,n,0,0);
    }
};