class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& coins,int k, int i,int j){
        int m=coins.size(),n=coins[0].size();
        if(i>=m || j>=n) return INT_MIN;
        if(i==m-1 && j==n-1){
            if(coins[i][j]<0 && k<2) return 0;
            return coins[i][j];
        }
        if(dp[i][j][k]!=INT_MIN) return dp[i][j][k];
        int res=INT_MIN;
        int take=coins[i][j]+max(solve(coins,k,i+1,j),solve(coins,k,i,j+1));
        res=max(res,take);
        if(coins[i][j]<0 && k<2){
            int skip=max(solve(coins,k+1,i,j+1),solve(coins,k+1,i+1,j));
            res=max(skip,res);
        }
       
        return dp[i][j][k]=res;

    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size(),n=coins[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        return solve(coins,0,0,0);
    }
};