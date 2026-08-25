class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums,int l,int r){
        int n=nums.size();
        if(l+1==r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=INT_MIN;
        for(int i=l+1;i<r;i++){
            int cost=nums[l]*nums[i]*nums[r]+solve(nums,l,i)+solve(nums,i,r);
            ans=max(ans,cost);
        }
        return dp[l][r]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> a(n+2,1);
        for(int i=0;i<n;i++) a[i+1]=nums[i];
        dp.assign(n+2,vector<int>(n+2,-1));
        return solve(a,0,n+1); 
    }
};