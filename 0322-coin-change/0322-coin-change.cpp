class Solution {
public:
    vector<int> memo;
    int dfs(vector<int>& coins, int rem){
        if(rem==0){
            return 0;
        }
        if(rem<0) return INT_MAX;
        
        if(memo[rem]!=-1) return memo[rem];
        int ans=INT_MAX;
        for(int c:coins){
            int res=dfs(coins,rem-c);
            if(res!=INT_MAX){
                ans=min(ans,1+res);
            }
        }
        return memo[rem]=ans;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount+1,-1);
        int ans=dfs(coins,amount);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};