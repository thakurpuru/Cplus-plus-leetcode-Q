class Solution {
public:
    long long solve(vector<int>& nums,int idx,vector<vector<long long>>& dp,int parity){
        if(idx==nums.size()){
            return 0;
        }
        if(dp[idx][parity]!=-1) return dp[idx][parity];
        long long take;
        if(parity==0){
            take=nums[idx]+solve(nums,idx+1,dp,1);
        }else{
            take=-nums[idx]+solve(nums,idx+1,dp,0);
        }
        
        long long skip=solve(nums,idx+1,dp,parity);
        return dp[idx][parity]=max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>path;
        vector<vector<long long>> dp(nums.size(),vector<long long>(2,-1));
        return solve(nums,0,dp,0);
    }
};