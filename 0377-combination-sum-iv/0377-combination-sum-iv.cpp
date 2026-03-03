class Solution {
public:
    int solve(vector<int>& nums,int target,vector<long long> &dp){
        if(target==0) return 1;
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        long long count=0;
        for(int i=0;i<nums.size();i++){
            count+=solve(nums,target-nums[i],dp);
        }
        return dp[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, -1);
        
        return solve(nums,target,dp); 
    }
};