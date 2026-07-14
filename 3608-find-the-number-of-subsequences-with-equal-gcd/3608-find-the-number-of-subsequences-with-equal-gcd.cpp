class Solution {
public:
    int mod=1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& nums,int i,int seq1,int seq2){
        
        if(i==nums.size()){ 
            if(seq1!=0 && seq2!=0 && seq1==seq2) return 1;
            return 0;
        }
        if(dp[i][seq1][seq2]!=-1) return dp[i][seq1][seq2];
        int count=0;
        count=(count+solve(nums,i+1,gcd(seq1,nums[i]),seq2))%mod;
        count=(count+solve(nums,i+1,seq1,gcd(seq2,nums[i])))%mod;
        count=(count+solve(nums,i+1,seq1,seq2))%mod;
        return dp[i][seq1][seq2]=count%mod;

    }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,vector<vector<int>>(201,vector<int>(201,-1)));
        
        return solve(nums,0,0,0)%mod;
    }
};