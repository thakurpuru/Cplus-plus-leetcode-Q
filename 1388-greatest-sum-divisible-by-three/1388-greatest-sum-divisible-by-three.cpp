class Solution {
public:
    int n;
    vector<int>num;
    vector<vector<int>>dp;
    int solve(int i,int sum){
        if(i==n){
            if(sum==0) return 0;
            return INT_MIN;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int take=num[i]+solve(i+1,(sum+num[i])%3);
        int nottake=solve(i+1,sum);
        return dp[i][sum]=max(take,nottake);
    }
    int maxSumDivThree(vector<int>& nums) {
        n=nums.size();
        num=nums;
        dp.assign(n + 1, vector<int>(3, -1));
        int ans=solve(0,0);
        return max(0,ans);
    }
};