class Solution {
public:
    
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        function<int(int,int)> subsequence=[&](int i,int j){
            if(i>j){
                return 0;
            }
            if(i==j) return 1;
            if(dp[i][j]!=-1) return dp[i][j];
            int ans=0;
            if(s[i]==s[j]){
                ans=2+subsequence(i+1,j-1);
            }else{
                ans=max(ans,max(subsequence(i+1,j),subsequence(i,j-1)));
            }

            return dp[i][j]=ans;
        };
        return subsequence(0,n-1);
        
    }
};