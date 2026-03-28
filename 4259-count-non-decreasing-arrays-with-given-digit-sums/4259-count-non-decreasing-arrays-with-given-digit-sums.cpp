class Solution {
public:
    int mod=1e9+7;
    bool check(int t,int sum){
        int a=0;
        while(t>0){
            a+=(t%10);
            t/=10;
        }
        return a==sum;
    }
    vector<vector<int>>dp;
    int solve(vector<int>& digitSum,int idx,int s){
        if(idx==digitSum.size()) return 1;
        if(s>5000) return 0;
        if(dp[idx][s]!=-1) return dp[idx][s];
        int res=0;
        if(check(s,digitSum[idx]))
        res=(res+solve(digitSum,idx+1,s))%mod;
        res=(res+solve(digitSum,idx,s+1))%mod;
        return dp[idx][s]=res;
    }
    int countArrays(vector<int>& digitSum) {
        dp.assign(digitSum.size(),vector<int>(5001,-1));
        return solve(digitSum,0,0);
    }
};